/**************************************************************
* 优势渗流带测井解释软件                                      *
* DKDMethod.cpp : implementation of the CDKDMethod class      *
*                                                             *
* Copyright (c) 1996  Start Petroleum Exploration Data Center.*
* All rights reserved.                                        *
*                                                             *
***************************************************************/

#include "DKD.h"
#include "DKDMethod.h"
#include "DepthProgdlg.h"
#include "stdafx.h"
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define e 2.71828

#define NNoI 10 //输入曲线数
#define NNoO 14 //输出曲线数
#define NNoC 31 //参数数

static INCURVE PInCurve[NNoI] = // 输入曲线结构
    {{"GR "}, {"SP "}, {"Rlld "}, {"Rlls "}, {"RXO "}, {"AC "}, {"DEN "}, {"RMN "}, {"RMG "}};

static OUTCURVE POutCurve[NNoO] = // 输出曲线结构
    {{"Vsh "}, {"Rmf "}, {"Rm "}, {"Por "}, {"Perm "}, {"Port "}, {"Swb "}, {"Md "}, {"R50 "}, {"Sw "}, {"Fw "}, {"Isp "}, {"Pdkd "}};

static INPNAME PNameC[NNoC] =                                                                                                                                                                                                                                                                                                 // 参数名
    {{"GRmin "}, {"GRmax "}, {"GCUR "}, {"GRwf "}, {"GRwb "}, {"Tma "}, {"Tf "}, {"Tsh "}, {"DENma "}, {"DENf "}, {"DENsh "}, {"Rlim "}, {"Uro "}, {"Urw "}, {"Rw "}, {"A "}, {"B "}, {"m "}, {"n "}, {"SHCT "}, {"PRCT "}, {"SPsd "}, {"SPsh "}, {"SSP "}, {"x "}, {"PA "}, {"PB "}, {"PC "}, {"Temp "}, {"fme "}, {"fn "}}; //岩性指数,1.6;

static float PARA[NNoC] = // 参数初始化值
    {0.0f, 150.0f, 3.0f, 130.0f, 120.0f, 168.0f, 620.0f, 450.0f, 2.71f, 1.0f, 2.25f, 2000.0f, 1.0f, 1.0f, 0.02f,
     1.0f, 1.0f, 2.0f, 2.0f, 50.0f, 5.0f, 20.0f, 140.0f, 60.0f, 1.6f, 2.0f, 2.0f, 2.0f, 120.0f, 2.0f, 2.0f};

CDKDMethod::CDKDMethod(const char *LogFileName, const char *InpFileName)
    : CLogProcess(LogFileName, InpFileName)
{
}

void CDKDMethod::Method(void)
{
    //从这儿开始，加入你的单点处理方法,替换示例。

    Isp = SPsh - SPsd;
    VshCaculate();  //泥质含量计算
    PorCaculate();  //孔隙度计算
    R50Caculate();  //R50计算
    PermCaculate(); //渗透率计算
    SwbCaculate();  //束缚水饱和度计算
    MdCaculate();   //粒度中值计算
    SwCaculate();   //含水饱和度计算
    FwCaculate();   //产水率计算
}

int CDKDMethod::Processing(void)
{
    //传递输入、输出曲线和参数，设置参数初值
    //使用你的实例替换示例
    InitIn(NNoI, PInCurve, (char *)&GR);
    InitPara(NNoC, PNameC, &GRmin);
    InitOut(NNoO, POutCurve, (char *)&Vsh);
    memcpy(&GRmin, &PARA, sizeof(PARA));

    //初始化缓冲区
    InitBuffer();

    if (DepLevel <= 0.0001)
    {
        AfxMessageBox(IDS_DEPTH_RELV_ZERO, MB_OK | MB_ICONERROR);
        return -1;
    }

    //产生进程条
    CDepthProgDlg m_Progress(SSdep, EEdep);
    m_Progress.Create(CWnd::GetActiveWindow());
    m_Progress.ShowWindow(SW_SHOW);
    CString szMsg;
    szMsg.LoadString(IDS_METHOD_INDICATOR1);
    m_Progress.SetWindowText(szMsg);

    while (!ReadInpCard())
    {
        Dep = Sdep;
        int PointNo = 0;
        while (Dep < Edep)
        {
            DatIn();
            Method();
            DatOut();
            PointNo++;
            Dep = Sdep + DepLevel * PointNo;
            m_Progress.SetDepth(Dep);
            if (m_Progress.CheckCancelButton())
                return 1;
        }
    }
    return 0; // 成功
}

void CDKDMethod::VshCaculate()
{
    ///////////////////////////////////////////////////////////////

    float Igr, b1, Rt, Rst, Iac, Iacsh;
    float C1, C2, Csp, VSHPsp, VSHPgr;
    switch (VshChoose)
    {
    case 0: //利用自然伽玛测井资料求取
    {
        Igr = (GR - GRmin) / (GRmax - GRmin); //自然伽马指数ΔGR=(GR-GRmin)/(GRmax-GRmin)
        Vsh = (pow(2, GCUR * Igr) - 1) / (pow(2, GCUR) - 1);
        break;
    }
    case 1: //用自然电位测井确定泥质含量
    {
        //	SSP=-69.975*log10(Rmf/Rw);               //Rm,泥浆电阻率;Rmf,泥浆滤液电阻率
        //	Rmf=C*pow(Rm,1.07);
        //	SSP=60;
        Vsh = 1 - SP / SSP;
        Vsh = 1.7 - pow((3.38 - pow((Vsh + 0.7), 2)), 0.5);
        break;
    }
    case 2: //用深浅侧向电阻率资料求取泥质含量
    {
        //	Rt=Rlld;         //或下面公式
        Rt = 2.589 * Rlld - 1.589 * Rlls;
        Rst = RXO / Rt;
        if (Rst >= 0.5)
        {
            b1 = 1.0;
        }
        else
            b1 = 0.5 / (1.0 - Rst);
        Vsh = pow((RXO * (Rlim - Rt) / (Rt * (Rlim - RXO))), b1); //Rlld Rlls深浅侧向电阻率，Rsh泥浆电阻率
        break;                                                    //Rlim油层最大电阻率，默认2000；
    }
    case 3: //利用声波资料求泥质含量
    {
        Iac = (AC - Tma) / (Tf - Tma);    //Tma骨架声波时差值（默认值为180.5 us/m）
        Iacsh = (Tsh - Tma) / (Tf - Tma); //Tf流体声波时差（默认值为620 us/m），Tsh泥质声波时差值
        Vsh = Iac / Iacsh;
        break;
    }
    case 4: //密度声波交会图计算泥质含量  (测井资料解释P180)
    {
        C1 = DEN * (Tma - Tf) - AC * (DENma - DENf) - DENf * Tma + DENma * Tf;
        C2 = (Tma - Tf) * (DENsh - DENf) - (DENma - DENf) * (DENsh - DENf);
        Vsh = C1 / C2;
        break;
    }
    case 5: //用GR-SP测井曲线值计算泥质含量
    {
        Csp = (SP - SPsd) / (SPsh - SPsd);
        Igr = (GR - GRmin) / (GRmax - GRmin);
        VSHPsp = ((pow(2, GCUR * Csp)) - 1) / (pow(2, GCUR) - 1);
        VSHPgr = (pow(2, GCUR * Igr) - 1) / (pow(2, GCUR) - 1);
        Vsh = (VSHPsp + VSHPgr) / 2;
        break;
    }
    }
    Vsh = 100 * Vsh;
}

void CDKDMethod::PorCaculate()
{
    /////////////////////////////////////////////////////////////////

    switch (PorChoose)
    {
    case 0: //声波理论值求取
    {
        Por = ((Tma - AC) / (Tma - Tf) - Vsh * ((Tma - Tsh) / (Tma - Tf)) / 100.0f);
        //	Por= (180-AC)/(180-620);
        break;
    }
    case 1: //用声波地区经验公式求取
    {
        //	x=1.6;
        Por = 1 - pow((Tma / AC), 1 / x);                               //x,岩性指数，砂岩，x=1.6;
        Por = 1 - pow((Tma / (AC - Vsh / 100.0 * (Tsh - Tma))), 1 / x); //经泥质校正后的公式

        break;
    }
    case 2: //用DEN测井曲线值计算孔隙度(理论公式)
    {
        Por = (DENma - DEN) / (DENma - DENf) - Vsh / 100.0 * ((DENma - DENsh) / (DENma - DENf));
        break;
    }
    }

    Por = 100.0 * Por;
    /////设置临界值
    if (Por > 50)
    {
        Por = 50;
    }
    else if (Por < PRCT || Vsh > SHCT) //孔隙度小于设置截止值，或者泥质含量大于设置截止值，孔隙度都为0
    {
        Por = 0;
    }
    else
    {
        Por = Por;
    }
}

void CDKDMethod::R50Caculate()
{
    ////////////////////////////////////////////////////////////////////

    switch (R50Choose)
    {
    case 0: //用渗透率求取孔隙半径
    {
        R50 = 1.6988 * log(Perm) + 9.3318;
        break;
    }
    case 1: //利用孔隙度求取孔隙半径
    {
        R50 = 4.0 * pow(10, -8) * pow(Por, 5.7933);
        break;
    }
    }
}

void CDKDMethod::PermCaculate()
{
    ////////////////////////////////////////////////////////////////////////

    float a0, a1, A3, P, N;
    switch (PermChoose)
    {
    case 0: //理论公式
    {
        //a0=3.5-5.0;
        //a1=0.2-0.4;
        //A3=0.08-0.2;
        a0 = 3.5;
        a1 = 0.2;
        A3 = 0.1;
        P = a0 + a1 / (log10(Por / A3));
        N = 1.1 / (log10(Por / A3));
        Perm = pow(10, (P + 7.1 * log10(Por) - N * log10(Swb))); //Swb影响
        break;
    }
    case 1: //利用岩心资料拟合孔隙度与渗透率关系
    {
        //	e=2.71828;
        Perm = 1.0 * pow(10, -7) * pow(e, (0.5456 * Por));
        break;
    }

    case 2: //用岩心资料拟合孔隙度粒度中值求取渗透率
    {
        Perm = pow(10, (7.6865 * log10(Por) + 2.3762 * log10(Md) - 9.4056)); //Md影响
        break;
    }

    case 3: //用泥质含量-孔隙度计算渗透率
    {
        //	Perm=0.8168*PermT+0.0679;   //PermT是渗透率岩心值，um2.
        Perm = pow(Por, PB) / pow(100 * Vsh, PC) * PA;
        break;
    }

    case 4: //地区经验公式
    {
        if (Por > 4)
        {
            Perm = pow((Por - 4), 9.32894) * 4.8046 * pow(10, -11);
        }
        else
        {
            Perm = 1.11;
        }
        if (Perm < 1.11)
        {
            Perm = 1.11;
        }
        else
        {
            Perm = Perm;
        }

        break;
    }
    }
}

void CDKDMethod::SwbCaculate()
{
    ///////////////////////////////////////////////////////////
    float DENmaa, Vdrymax; //DENdry;
    switch (SwbChoose)
    {
    case 0: //孔隙度比值法
    {
        break;
    }
    case 1: //视骨架密度法
    {
        DENmaa = (DEN - Por / 100.0 * DENf) / (1 - Por / 100.0); //Vdrymax,干粘土含量最大值
        Vdrymax = (DENmaa - 2.65) / (3 - 2.65);                  //=(DENmaa-DENma)/(DENdry-DENma)
        //	Swb=(Vsh-Vshdry)/Por=(Vsh-Vdrymax(1-Por))/Por=(Vsh-Vdrymax)/Por+Vdrymax;
        Swb = (Vsh / 100.0 - Vdrymax) / Por + Vdrymax;
        break;
    }
    case 2: //自然伽马法
    {
        Swb = (GR - GRwf) / (GRwb - GRwf); //GRwf,100%自由水时自然伽玛值
        break;                             //GRwb,100%束缚水时自然伽玛值
    }
    case 3:
    {

        break;
    }
    case 4:
    {
        break;
    }
    case 5:
    {
        //	Swb=pow(Perm,-0.201759)*117.63/100.0;  //for 辽河
        Swb = (115 * (2.65 * (1.0 - Por / 100.0) + 1.0 * Por / 100.0) - 1.5 * Por - 181.2) / 100.0; //for 大庆
        //	f=A1/pow(por,Am1);
        //	Swb=pow((f*Rw/Rlim),1.0/An);
        break;
    }
    }
    ///////设置截止值
    Swb = Swb * 100.0;
    if (Swb >= 100.0)
    {
        Swb = 99.99;
    }
    else if (Swb <= 0.0)
    {
        Swb = 0.01;
    }
    else if (Swb > Sw)
    {
        Swb = Swb;
    }
}

void CDKDMethod::MdCaculate()
{
    ///////////////////////////////////////////////////////////////////

    float Igr, C0, C1;
    switch (MdChoose)
    {
    case 0: //地区经验公式求取粒度中值
    {
        C0 = 0.18;                            //区块地区经验值
        Igr = (GR - GRmin) / (GRmax - GRmin); //C0、C1为经验系数,Co为GRmin层段时的粒度中值Md0
        //Co=log10(Md0);
        C1 = 1.75 - C0;
        Md = pow(10, (C0 + C1 * Igr));
        //	Md=pow(10.0,(-0.2877-0.0713*Igr));
        break;
    }
    }
}

void CDKDMethod::SwCaculate()
{
    //////////////////////////////////////////////////////

    float Rt;
    switch (SwChoose)
    {
    case 0: //用S-B模型求解含水饱和度
    {
        //	Rt=Rlld;
        Sw = (double)satw(Rw, Rlld, Por, Port, Temp, Vsh, RXO, fme, fn);

        break;
    }
    case 1: //阿尔奇计算含水饱和度
    {
        //	Rt=Rlld;         //或下面公式
        //	Rt=2.589*Rlld-1.589*Rlls;
        Sw = pow((A * B * Rw) / (Rlld * pow(Por, m)), 1 / n) * 100;
        //	Sw =pow((A*B*Rw)/(Rlld*pow(Por/100,m)),1/n)*100;
        //		SoP =100-(pow((A*B*Rw)/(RT*pow(POR/100,m)),1/n))*100;
        break;
    }
    }
}

void CDKDMethod::FwCaculate()
{
    ////////////////////////////////////////////////////////////

    float Kro, Krw;
    switch (FwChoose)
    {
    case 0: //琼斯(Junse)公式计算产水率(中)
    {
        Krw = pow((Sw - Swb) / (1 - Swb), 3);   //Qw,产水量;Qo,产油量;Kro、Krw,油、水的相对渗透率；
        Kro = pow((0.9 - Sw) / (0.9 - Swb), 2); //Uro、Urw,油、水的相对粘度(mpa*s)
        Fw = 1 / (1 + Kro / Krw * Uro / Urw);   //=Qw/(Qo+Qw)
        break;
    }

    case 1: //彼尔逊公式计算产水率(强)
    {
        Krw = pow((Sw - Swb) / (1 - Swb), 0.5);
        Kro = pow((1 - Sw) / (1 - Swb), 2);
        Fw = 1 / (1 + Kro / Krw * Uro / Urw); //=Qw/(Qo+Qw)
        break;
    }
        ////////////////////////////////
        if (Fw >= 1.0)
        {
            Fw = 0.9999;
        }
        else if (Fw <= 0)
        {
            Fw = 0.0001;
        }
        else
        {
            Fw = Fw;
        }
    }
}

void CDKDMethod::PdkdCaculate()
{
    ////////////////////////////////////////////////////////////
    float m1;
    switch (PdkdChoose)
    {
    case 0:
    { //优势渗流带参数计算
        Pdkd = SP * Perm * Sw * Por / (RMN * RMG * Vsh);
        break;
    }
    case 1:
    { //优势渗流带参数计算(带Md)
        Pdkd = SP * Perm * Sw * Por * Md / (RMN * RMG * Rlld * Rlls * Vsh);
        break;
    }
    case 2:
    { //优势渗流带参数计算(带R2.5)
        Pdkd = SP * Perm * Sw * Por / (m1 * R50 * Vsh);
        break;
    }
    case 3:
    { //优势渗流带参数计算(薄层)
        // Pdkd=Rlld*RMN*D/(SP*RMG);
        break;
    }
    }
}

double CDKDMethod::satw(double Rw, double Rlld, double Por, double Port, double Temp, double Vsh, double RXO, double fme, double fn)
{

    //因为pow(double,float)两个变量类型不统一所以出错的！！
    double cw, ct, sw6, sal, vfdl, qv, fe, ctemp, vu, arfa, eneq; //用double型！！
    double fg, h, fneq, ffneq, ceqq, ceq, cceq, sw2, sw3, y, y1, sw1, sw, am;
    int i;
    cw = 1. / Rw;
    ct = 1. / Rlld;
    sw6 = 0.6;
    sal = (3.562 - log10(Rw - 0.0123)) / 0.955;
    sal = pow(10.0, sal) / 1000.0;
    sal = sal / 58.453;
    vfdl = 1. - Por / Port;
    qv = vfdl / (0.084 / pow(sal, 0.5) + 0.22);
    fe = pow(Port, -fme);
    ctemp = (Temp - 39.0) * 5.0 / 9.0;
    vu = 0.3 * (295. + 25.) / (ctemp + 25.0 + 273.15);
    arfa = (0.084 / pow(sal, 0.5) + 0.22) / vu;
    if (arfa < 1.0)
        arfa = 1.;
    eneq = 3.571 / ((sqrt(arfa) - 0.188) * (sqrt(arfa) - 0.188));
    ceqq = float(12.645 + 7.6725 * sqrt(eneq));
    ceq = ceqq / (1. + 1.3164 * sqrt(eneq));
    if (eneq > 0.5)
    {
        ffneq = 1. + 0.0383 * (eneq - 0.5);
        fneq = ffneq + 0.01761 * (eneq - 0.5) * (eneq - 0.5);
    }
    else
        fneq = 1.0;
    h = 0.6696 + 1.1796 * vfdl - 0.14426 * vfdl * vfdl;
    fg = pow(arfa, 1. / h);
    cceq = ceq / fg / fneq;
    sw2 = qv * cceq / cw - vfdl;
    sw3 = fe * ct / cw;
    i = 0;
_300:
    i = i + 1;
    if ((sw3 * sw6 / (sw6 + sw2)) <= 0.0)
        goto _112;
    y = pow(sw3 * sw6 / (sw6 + sw2), 1. / fn) - sw6;
    y1 = (1. / fn) * pow(sw6 * sw3 / (sw6 + sw2), 1. / fn - 1.) * sw2 * sw3 / ((sw6 + sw2) * (sw6 + sw2)) - 1.;
    sw1 = sw6 - y / y1;
    if (fabs(sw1 - sw6) < 1e-6)
        goto _949;
    sw6 = sw1;
    if (i == 300)
        goto _112;
    goto _300;
_949:
    sw = sw1;
    goto _380;
_112:
    am = (float)2.2 - (0.035 / (Por + 0.042));
    sw = (-Vsh / RXO + sqrt((Vsh / RXO) * (Vsh / RXO) + 5.0 * pow(Por, am) /
                                                            (Rlld * Rw * pow(1. - Vsh, am - 1.0)))) *
         (0.4 * Rw * pow(1. - Vsh, am - 1.0)) / pow(Por, am);
    sw = 1.0 - Por * (1.0 - sw) / Port;
_380:
    if (sw >= 1.)
        sw = 0.9999;
    if (sw <= 0.)
        sw = 0.0001;
    return (sw);
}

// DKDComputing.cpp : implementation file
//

#include "DKD.h"
#include "DKDComputing.h"
#include "LogIO.h"
#include "Perm.h" // Added by ClassView
#include "Por.h"  // Added by ClassView
#include "Sw.h"   // Added by ClassView
#include "Swb.h"  // Added by ClassView
#include "Vsh.h"  // Added by ClassView
#include "stdafx.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CDKDComputing dialog

CDKDComputing::CDKDComputing(CWnd *pParent /*=NULL*/)
    : CDialog(CDKDComputing::IDD, pParent)
{
    //{{AFX_DATA_INIT(CDKDComputing)
    //}}AFX_DATA_INIT
}

void CDKDComputing::DoDataExchange(CDataExchange *pDX)
{
    CDialog::DoDataExchange(pDX);
    //{{AFX_DATA_MAP(CDKDComputing)
    DDX_Control(pDX, IDC_TABTEST, m_Tab);
    //}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CDKDComputing, CDialog)
//{{AFX_MSG_MAP(CDKDComputing)
ON_NOTIFY(TCN_SELCHANGE, IDC_TABTEST, OnSelchangeTabtest)
ON_BN_CLICKED(IDC_Calculate, OnCalculate)
//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CDKDComputing message handlers

BOOL CDKDComputing::OnInitDialog()
{
    CDialog::OnInitDialog();

    // TODO: Add extra initialization here

    ReadFromWis();

    //为Tab Control增加三个页面

    m_Tab.InsertItem(0, "泥质含量");
    m_Tab.InsertItem(1, "孔隙度");
    m_Tab.InsertItem(2, "渗透率");
    m_Tab.InsertItem(3, "束缚水饱和度");
    m_Tab.InsertItem(4, "含水饱和度");
    m_Tab.InsertItem(5, "优势渗流带参数");

    //调整子对话框在父窗口中的位置
    CRect rect;
    m_Tab.GetClientRect(&rect); //获得TAB控件的坐标
    rect.top += 25;
    rect.bottom -= 5;
    rect.left += 15;
    rect.right -= 5;

    //创建三个对话框
    m_Vsh.Create(IDD_Vsh, &m_Tab);
    m_Por.Create(IDD_Por, &m_Tab);
    m_Perm.Create(IDD_Perm, &m_Tab);
    m_Swb.Create(IDD_Swb, &m_Tab);
    m_Sw.Create(IDD_Sw, &m_Tab);
    m_Pdkd.Create(IDD_Pdkd, &m_Tab);

    //设置子对话框尺寸并移动到指定位置
    m_Vsh.MoveWindow(&rect);
    m_Por.MoveWindow(&rect);
    m_Perm.MoveWindow(&rect);
    m_Swb.MoveWindow(&rect);
    m_Sw.MoveWindow(&rect);
    m_Pdkd.MoveWindow(&rect);

    //把对话框对象指针保存起来
    pDialog[0] = &m_Vsh;
    pDialog[1] = &m_Por;
    pDialog[2] = &m_Perm;
    pDialog[3] = &m_Swb;
    pDialog[4] = &m_Sw;
    pDialog[5] = &m_Pdkd;

    //显示初始页面
    pDialog[0]->ShowWindow(SW_SHOW);
    pDialog[1]->ShowWindow(SW_HIDE);
    pDialog[2]->ShowWindow(SW_HIDE);
    pDialog[3]->ShowWindow(SW_HIDE);
    pDialog[4]->ShowWindow(SW_HIDE);
    pDialog[5]->ShowWindow(SW_HIDE);

    //保存当前选择
    m_Tab.SetCurSel(0);

    return TRUE; // return TRUE unless you set the focus to a control
                 // EXCEPTION: OCX Property Pages should return FALSE
}

void CDKDComputing::OnSelchangeTabtest(NMHDR *pNMHDR, LRESULT *pResult)
{
    // TODO: Add your control notification handler code here

    int CurSel = m_Tab.GetCurSel();
    switch (CurSel)
    {
    case 0:
        m_Vsh.ShowWindow(SW_SHOW);
        m_Por.ShowWindow(SW_HIDE);
        m_Perm.ShowWindow(SW_HIDE);
        m_Swb.ShowWindow(SW_HIDE);
        m_Sw.ShowWindow(SW_HIDE);
        m_Pdkd.ShowWindow(SW_HIDE);
        break;
    case 1:
        m_Vsh.ShowWindow(SW_HIDE);
        m_Por.ShowWindow(SW_SHOW);
        m_Perm.ShowWindow(SW_HIDE);
        m_Swb.ShowWindow(SW_HIDE);
        m_Sw.ShowWindow(SW_HIDE);
        m_Pdkd.ShowWindow(SW_HIDE);
        break;
    case 2:
        m_Vsh.ShowWindow(SW_HIDE);
        m_Por.ShowWindow(SW_HIDE);
        m_Perm.ShowWindow(SW_SHOW);
        m_Swb.ShowWindow(SW_HIDE);
        m_Sw.ShowWindow(SW_HIDE);
        m_Pdkd.ShowWindow(SW_HIDE);
        break;
    case 3:
        m_Vsh.ShowWindow(SW_HIDE);
        m_Por.ShowWindow(SW_HIDE);
        m_Perm.ShowWindow(SW_HIDE);
        m_Swb.ShowWindow(SW_SHOW);
        m_Sw.ShowWindow(SW_HIDE);
        m_Pdkd.ShowWindow(SW_HIDE);
        break;
    case 4:
        m_Vsh.ShowWindow(SW_HIDE);
        m_Por.ShowWindow(SW_HIDE);
        m_Perm.ShowWindow(SW_HIDE);
        m_Swb.ShowWindow(SW_HIDE);
        m_Sw.ShowWindow(SW_SHOW);
        m_Pdkd.ShowWindow(SW_HIDE);
        break;
    case 5:
        m_Vsh.ShowWindow(SW_HIDE);
        m_Por.ShowWindow(SW_HIDE);
        m_Perm.ShowWindow(SW_HIDE);
        m_Swb.ShowWindow(SW_HIDE);
        m_Sw.ShowWindow(SW_HIDE);
        m_Pdkd.ShowWindow(SW_SHOW);
        break;
    default:
        break;
    }

    *pResult = 0;
}

void CDKDComputing::OnCalculate()
{
    // TODO: Add your control notification handler code here
    //将计算方法选择保存至全局变量

    VshChoose = m_Vsh.m_VSH;

    PorChoose = m_Por.m_POR;

    R50Choose = m_Por.m_R50;

    PermChoose = m_Perm.m_PERM;

    SwbChoose = m_Swb.m_SWB;

    MdChoose = m_Sw.m_MD;

    SwChoose = m_Sw.m_SW;

    FwChoose = m_Sw.m_FW;

    PdkdChoose = m_Pdkd.m_Pdkd;

    SaveToWis();

    CDialog::OnOK();
}

void CDKDComputing::OnCancel()
{
    // TODO: Add extra cleanup here

    CDialog::OnCancel();
}

void CDKDComputing::SaveToWis()
{

    //将计算方法选择状态存入wis文件
    class WIS_DKD_MethodData
    {
      public:
        int m_DATA_Vsh;
        int m_DATA_POR;
        int m_DATA_R50;
        int m_DATA_PERM;
        int m_DATA_Swb;
        int m_DATA_MD;
        int m_DATA_Sw;
        int m_DATA_Fw;
        int m_DATA_Pdkd;
        WIS_DKD_MethodData(){};
    };

    //将解释参数保存至WIS文件中
    WIS_DKD_MethodData m_MethodData[1];

    m_MethodData[0].m_DATA_Vsh = m_Vsh.m_VSH;
    m_MethodData[0].m_DATA_POR = m_Por.m_POR;
    m_MethodData[0].m_DATA_R50 = m_Por.m_R50;
    m_MethodData[0].m_DATA_PERM = m_Perm.m_PERM;
    m_MethodData[0].m_DATA_Swb = m_Swb.m_SWB;
    m_MethodData[0].m_DATA_MD = m_Sw.m_MD;
    m_MethodData[0].m_DATA_Sw = m_Sw.m_SW;
    m_MethodData[0].m_DATA_Fw = m_Sw.m_FW;
    m_MethodData[0].m_DATA_Pdkd = m_Pdkd.m_Pdkd;

    CWisIO m_wis(WisFileName);
    if (!m_wis.Open(CWisIO::modeReadWrite | CWisIO::shareDenyWrite))
    {
        return; //打开WIS文件失败退出
    }

    //将曲线取值数据保存到PNN_METHODDATA表格中

    int indexnum = m_wis.OpenTable("DKD_METHODDATA"); //若存在表对象则打开

    if (indexnum < 0)
    {
        indexnum = m_wis.CreateTable(0, "DKD_METHODDATA"); //若不存在表对象则建立表对象
    }

    if (indexnum >= 0)
    {
        m_wis.SetTableRecordCount(indexnum, 0);
        int numtemp = m_wis.WriteTableRecord(indexnum, 0, 1, m_MethodData); //将m_MethodData数组中数据存至DKD_METHODDATA表中
        m_wis.CloseTable(indexnum);
    }
    m_wis.Close();
}

void CDKDComputing::ReadFromWis()
{
    class WIS_DKD_MethodData
    {
      public:
        int m_DATA_Vsh;
        int m_DATA_POR;
        int m_DATA_R50;
        int m_DATA_PERM;
        int m_DATA_Swb;
        int m_DATA_MD;
        int m_DATA_Sw;
        int m_DATA_Fw;
        int m_DATA_Pdkd;
        WIS_DKD_MethodData(){};
    };

    CWisIO m_wis(WisFileName);

    if (!m_wis.Open(CWisIO::modeReadWrite | CWisIO::shareDenyWrite))
        return; //打开WIS文件失败退出

    int indexnum = m_wis.OpenTable("DKD_METHODDATA"); //若存在表对象则打开

    if (0 > indexnum)
        return; //打开表出错退出

    if (!m_wis.GetTableRecordCount(indexnum))
        return;

    WIS_DKD_MethodData m_MethodData[1];

    m_wis.ReadTableRecord(indexnum, 0, 1, m_MethodData);
    m_wis.CloseTable(indexnum);
    m_wis.Close();
    //将表格中的数据显示到对话框中

    m_Vsh.m_VSH = m_MethodData[0].m_DATA_Vsh;
    m_Por.m_POR = m_MethodData[0].m_DATA_POR;
    m_Por.m_R50 = m_MethodData[0].m_DATA_R50;
    m_Perm.m_PERM = m_MethodData[0].m_DATA_PERM;
    m_Swb.m_SWB = m_MethodData[0].m_DATA_Swb;
    m_Sw.m_MD = m_MethodData[0].m_DATA_MD;
    m_Sw.m_SW = m_MethodData[0].m_DATA_Sw;
    m_Sw.m_FW = m_MethodData[0].m_DATA_Fw;
    m_Pdkd.m_Pdkd = m_MethodData[0].m_DATA_Pdkd;

    UpdateData(FALSE);
}
