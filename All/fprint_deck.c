#include "project.h"

void fprint_deck(deck *x,FILE *fd){
    for (int i = 0; i < x->height; i++)
    {
        fprint_card(&(x->remain)[i],fd);
    }
    fprintf(fd,"\n");
}
