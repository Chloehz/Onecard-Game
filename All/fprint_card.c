#include "project.h"

void fprint_card(card* x,FILE *fd){
    char number[13][3]={"2","3","4","5","6","7","8","9","10","J","Q","K","A"};
    char suit[4][9]={"Spades","Hearts","Diamonds","Clubs"};
    fprintf(fd,"%s %s  ",suit[x->suit-1],number[x->num-2]);
}
