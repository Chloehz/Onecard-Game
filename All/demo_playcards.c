#include "project.h"

int demo_playcards(linklist *currenplayer,deck *discard){
    int fg;int cardo=-1;
    for (int i = 0; i < currenplayer->cardinhand.height; i++)
    {
        fg=checkIfFollowingCard(&(currenplayer->cardinhand.remain)[i],discard);
        if(fg==0){
            sleep(1);
            cardo=i+1;
            printf("%d\n",cardo);
            break;
        }
    }
    return cardo;    
}
