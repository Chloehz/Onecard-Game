#include "project.h"

int isWin(linklist *currentplayer){
    int result=0;
    if ((currentplayer->cardinhand.height)==0)//currentplayer wins!
    {
        printf("Player %d wins!\n",currentplayer->id);
        result=1;
    }
    return result;
}
