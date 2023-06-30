#include "project.h"

int could_play(linklist *currentplayer,game *total){
    int check=1;//if check==1 then the turn finished
    for (int i = 0; i < (currentplayer->cardinhand.height); i++)
    {
        check=checkIfFollowingCard(&(currentplayer->cardinhand.remain)[i],&(total->discard));
        if(check==0)
            break;
    }
    if (check==1)
    {
        printf("Player %d draws: ",currentplayer->id);
        fprintf(total->fd,"Player %d draws: ",currentplayer->id);
        card temp;
        if ((total->stock.height)==0)
            exchange_deck(&(total->stock),&(total->discard));
        get_from_deck(&(total->stock),&temp);
        card_print(&temp);
        fprint_card(&temp,total->fd);
        printf(" \n");
        fprintf(total->fd," \n");
        put_to_deck(&temp,&(currentplayer->cardinhand));
    }
    return check;
}
