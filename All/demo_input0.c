#include "project.h"

int demo_input0(game *total){
    int input=-1;
    switch (total->a)
    {
    case 0:
        if(scanf("%d",&input)){};
        break;
    case 1:
        sleep(1);
        printf("0\n");
        input=0;
        break;
    default:
        break;
    }
    return input;
}
