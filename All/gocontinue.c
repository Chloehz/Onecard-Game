#include "project.h"

void gocontinue(linklist **currentplayer,cardaction *action){
    if(action->turn==1)
    {
        if (action->isskip==0)
            *currentplayer=(*currentplayer)->next;
        else
            *currentplayer=(*currentplayer)->next->next;        
    }
    else
    {
        if (action->isskip==0)
            *currentplayer=(*currentplayer)->pre;
        else
            *currentplayer=(*currentplayer)->pre->pre;        
    }
    action->isskip=0;
}
