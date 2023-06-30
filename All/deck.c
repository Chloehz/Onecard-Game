#include "project.h"

void init_deck(deck * x,int d){
    x->height=0;
    x->remain=(card*)malloc((unsigned long)(52*d)*sizeof(card));
    for (int i = 0; i < 52*d; i++){
        card_init(&((x->remain)[i]));
    }   
}

void destroy_deck(deck *x){
    free(x->remain);
}

void draw_deck(deck *x,deck *y){
    card temp;
    card_init(&temp);
    get_from_deck(x,&temp);
    put_to_deck(&temp,y);
}

void exchange_deck(deck *x,deck *y){
    deck temp;
    temp=*x;
    *x=*y;
    *y=temp;
}

void get_from_deck(deck *x,card *y){
    card temp=x->remain[x->height-1];//haven't finish deck empty
    x->height--;
    *y=temp;
}

void print_deck(deck *x){
    for (int i = 0; i < x->height; i++)
    {
        card_print(&(x->remain)[i]);
    }
    printf("\n");
}

void put_to_deck(card *x,deck *y){
    (y->height)++;
    (*y).remain[(y->height)-1]=*x;
    card_init(x);
}

void shuffle_deck(deck *x){
    int num1,num2;card temp;
    srand((unsigned)time(NULL));
    for (int i = 0; i < x->height ; i++)
    {
        num1=rand()%x->height;
        num2=rand()%x->height;
        temp=(x->remain)[num1];
        (x->remain)[num1]=(x->remain)[num2];
        (x->remain)[num2]=temp;
    }
}

void sort_deck(deck *x){
    for (int i = 0; i < x->height-1; i++)
    {
        for (int j = 0; j < x->height-i-1; j++)
        {
            card temp;
            int compare=card_compare(&(x->remain)[j],&(x->remain)[j+1]);
            if (compare==1)
            {
                temp=x->remain[j];
                x->remain[j]=x->remain[j+1];
                x->remain[j+1]=temp;
            }   
        }    
    }    
}
