#include "project.h"

void end_the_round(int n,game *total){
    for (int i = 0; i < n; i++)
    {
        printf("Player %d: %d, ",i+1,-(total->player)[i].cardinhand.height);
        fprintf(total->fd,"Player %d: %d, ",i+1,-(total->player)[i].cardinhand.height);
        (total->player)[i].score=(total->player)[i].score-(total->player)[i].cardinhand.height;
        printf("total: %d\n",(total->player)[i].score);
        fprintf(total->fd,"total: %d\n",(total->player)[i].score);
    }   
}
