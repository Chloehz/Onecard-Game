#include "project.h"

void card_init(card* x){
    x->num = 0;
    x->suit = 0;
}


void card_print(card* x){
    char number[13][3]={"2","3","4","5","6","7","8","9","10","J","Q","K","A"};
    char suit[4][9]={"Spades","Hearts","Diamonds","Clubs"};
    printf("%s %s  ",suit[x->suit-1],number[x->num-2]);
}


// return 0 if x1 equal x2, 1 x1>x2, -1 x1<x2
int card_compare(card* x1, card* x2) {
    int c1, c2;
    if(x1->suit == x2->suit && x1->num == x2->num)
        return 0;

    c1 = x1->suit * 15 + x1->num;
    c2 = x2->suit * 15 + x2->num;

    return c1>c2 ? 1 : -1; 
}
