#include "project.h"

void init_game(int n,int c,int d,int r,int a,FILE *fd,game *total){
    //init discard and stock
    init_deck(&(total->discard),d);
    init_deck(&(total->stock),d);
    //check if played in auto demo
    total->a=a;
    total->fd=fd;
    //put cards into stock
    total->stock.height=52*d;
    for (int i = 0; i < 52*d; i++)
    {
        (total->stock.remain)[i].suit=(int)(i/(13*d))+1;
        (total->stock.remain)[i].num=((int)((i/d))%13)+2;
    }
    fprintf(total->fd,"Initial unshuffled cards:\n");
    fprint_deck(&(total->stock),total->fd);
    shuffle_deck(&(total->stock));
    fprintf(total->fd,"Shuffle result:\n");
    fprint_deck(&(total->stock),total->fd);
    if (a==1)
    {
        printf("Shuffle result:\n");
        print_deck(&(total->stock));
    }   
    //then init players
    if (r==1)
        total->player=(linklist*)malloc((unsigned long)n*sizeof(linklist));
    for (int i = 0; i < n; i++)
    {
        if (r==1)
        {
            (total->player)[i].id=i+1;
            (total->player)[i].score=0;
            int pre_=(i-1==-1?(n-1):(i-1));//link together
            int next_=(i+1==n?0:(i+1));
            (total->player)[i].next=&((total->player)[next_]);
            (total->player)[i].pre=&((total->player)[pre_]);
        }
        init_deck(&(total->player[i].cardinhand),d);
    }
    //draw cards for each player
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < c; j++)
        {
            if (total->stock.height==0)
                exchange_deck(&(total->stock),&(total->discard));
            draw_deck(&(total->stock),&((total->player)[i].cardinhand));
        }   
        sort_deck(&((total->player)[i].cardinhand));
    }
    
}
