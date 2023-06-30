#include "project.h"

void cardAction(game *total,cardaction *action,card *played,linklist *currentplayer){
    if (played->num==2)
        (action->numToDraw)+=2;
    else if (played->num==3)
        (action->numToDraw)+=3;
    else if (played->num==7)
        (action->numToDraw)=0;
    else if (played->num==11)    
        (action->isskip)=1;
    else if (played->num==12)
        (action->turn)=1-(action->turn);
    else
    {
        if (action->numToDraw!=0)
        {
            printf("Player %d draws: ",currentplayer->id);
            fprintf(total->fd,"Player %d draws: ",currentplayer->id);
            for (int i = 0; i < action->numToDraw; i++)
            {            
                card temp;
                if ((total->stock.height)==0)
                    exchange_deck(&(total->stock),&(total->discard));
                get_from_deck(&(total->stock),&temp);
                card_print(&temp);
                fprint_card(&temp,total->fd);
                put_to_deck(&temp,&(currentplayer->cardinhand));
            }
            printf(" \n");
            fprintf(total->fd," \n");
        }
        action->numToDraw=0;
    }
}
