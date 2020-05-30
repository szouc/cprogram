#include <pthread.h>
#include <stdio.h>

unsigned long long gsum = 0;
_Bool isfinisum = 0;

void *cusum_thrd(void *prag)
{
    while (*(unsigned long long *)prag)
        gsum += (*(unsigned long long *)prag)--;
    isfinisum = 1;
    return NULL;
}

int main(void)
{
    pthread_attr_t attr;
    pthread_attr_init(&attr);
    pthread_attr_setdetachstate(&attr, PTHREAD_CREATE_DETACHED);

    pthread_t thrd;
    unsigned long long m = 1000000000;
    if (pthread_create(&thrd, &attr, cusum_thrd, &m) != 0)
        return printf("Fail to create thread.\n");
    pthread_attr_destroy(&attr);

    while (isfinisum == 0)
        printf("\r %lld", gsum);
    printf("\r %lld", gsum);
}
