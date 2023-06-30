#include "project.h"

void change_cardinhand(deck *x,int number){
    for (int i = number; i < x->height; i++)
    {
        (x->remain)[i-1]=(x->remain)[i];
    }
    x->height--;   
}
