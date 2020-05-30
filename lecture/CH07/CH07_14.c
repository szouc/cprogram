
#include <stdio.h>

enum Level {error = 0, warning, info};
int main(void) {
    enum Level message_level;
    message_level = error;
    if(message_level >= error)
    {
        printf("[ERROR]: \n");
    }
    if(message_level >= warning)
    {
        printf("[WARNING]: \n");
    }
    if(message_level >= info)
    {
        printf("[INFO]: \n");
    }
    return 0;
}