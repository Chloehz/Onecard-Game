#include "project.h"

void if_clear(game *total){
    if (total->a==0)
    {
        printf("Print 0 to clear the screen:");
        int cl;
        if(scanf("%d",&cl)){};
        if(cl==0)
            clear_screen();
    }
    else
        sleep(1);   
}
