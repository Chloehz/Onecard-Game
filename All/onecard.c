#include "project.h"

void onecard(int c,int n,int d,int r,int a,FILE *fd){
    game total;//to store discard stock and players
    printf("---- Initial setup ----\n");
    printf("Number of rounds: %d\n",r);
    printf("Number of decks: %d\n",d);
    printf("Number of players: %d\n",n);
    printf("\nShuffling cards...\n");
    fprintf(fd,"---- Initial setup ----\n");
    fprintf(fd,"Number of rounds: %d\n",r);
    fprintf(fd,"Number of decks: %d\n",d);
    fprintf(fd,"Number of players: %d\n",n);
    fprintf(fd,"\nShuffling cards...\n");
    //init game and output the initial cards
    init_game(n,c,d,1,a,fd,&total);
    printf("\nDealing cards...\n");
    fprintf(total.fd,"\nDealing cards...\n");
    for (int i = 0; i < n; i++)//this part may be later included in print_player function
    {
        printf("Player %d: ",i+1);
        sort_deck(&(total.player)[i].cardinhand);
        fprintf(total.fd,"Player %d: ",i+1);
        fprint_deck(&(total.player)[i].cardinhand,total.fd);
        printf("Print 0 to see your initial cards: ");int see;
        see=demo_input0(&total);
        if(see==0)
            print_deck(&(total.player)[i].cardinhand);
        if_clear(&total);
    }
    printf("\nDetermining the playing order...\n");
    fprintf(total.fd,"\nDetermining the playing order...\n");
    int order=0;int min=1000;//order is the begginner
    for (int i = 0; i < n; i++)
    {
        card draw;int cp;
        if (total.stock.height==0)
            exchange_deck(&(total.stock),&(total.discard));
        get_from_deck(&(total.stock),&draw);
        cp=(draw.suit)*15+draw.num;
        if(cp<min)
        {
            order=i;
            min=cp;
        }
        printf("Player %d: ",i+1);
        fprintf(total.fd,"Player %d: ",i+1);
        card_print(&draw);
        fprint_card(&draw,total.fd);
        printf(" \n");
        fprintf(total.fd," \n");
        put_to_deck(&draw,&(total.discard));
    }
    printf("\nThe game will start with player %d\n",order+1);
    fprintf(total.fd,"\nThe game will start with player %d\n",order+1);
    cardaction action;linklist *currentplayer;
    currentplayer=&(total.player[order]);
    int result;//to check if someone wins
    for (int i = 1; i <= r; i++)//played for r rounds
    {
        if (i!=1)
        {
            init_game(n,c,d,i,a,fd,&total);
            for (int j = 0; j < n; j++)
            {
                int see;
                printf("Player %d: ",j+1);
                sort_deck(&(total.player)[j].cardinhand);
                fprintf(total.fd,"Player %d: ",j+1);
                fprint_deck(&(total.player)[j].cardinhand,total.fd);
                printf("Print 0 to see your initial cards: ");
                see=demo_input0(&total);
                if(see==0)
                    print_deck(&(total.player)[j].cardinhand);
                if_clear(&total);
            }    
        }        
        printf("Round %d\n",i);
        fprintf(total.fd,"Round %d\n",i);
        //draw the first card
        printf("First card: ");
        fprintf(total.fd,"First card: ");
        card firstcard;
        if (total.stock.height==0)
            exchange_deck(&(total.stock),&(total.discard));
        get_from_deck(&(total.stock),&firstcard);
        card_print(&firstcard);
        printf(" \n");
        fprint_card(&firstcard,total.fd);
        fprintf(total.fd," \n");
        put_to_deck(&firstcard,&(total.discard));
        //then the game starts
        action.turn=1;action.numToDraw=0;action.isskip=0;
        result=0;
        while (result==0)
        {
            int start;
            if_clear(&total);
            fprintf(total.fd,"\nThe previous card: ");
            fprint_card(&(total.discard.remain[total.discard.height-1]),total.fd);
            printf("\nPrint 0 to start your turn: ");
            start=demo_input0(&total);
            if(start==0)
                printf("The previous card: ");
            card_print(&(total.discard.remain[total.discard.height-1]));
            printf("\nPlayer %d current cards: ",currentplayer->id);
            print_deck(&(currentplayer->cardinhand));
            fprintf(total.fd,"\nPlayer %d current cards: ",currentplayer->id);
            fprint_deck(&(currentplayer->cardinhand),total.fd);
            int check=could_play(currentplayer,&total);
            card played;
            if (check==1)//the current player cant play
            {
                printf("Player %d cards: ",currentplayer->id);
                fprintf(total.fd,"Player %d cards: ",currentplayer->id);
                sort_deck(&(currentplayer->cardinhand));
                print_deck(&(currentplayer->cardinhand));
                fprint_deck(&(currentplayer->cardinhand),total.fd);
                gocontinue(&currentplayer,&action);
                continue;
            }
            int fg;int number;
            printf("Player %d plays(1-%d): ",currentplayer->id,currentplayer->cardinhand.height);
            fprintf(total.fd,"Player %d plays(1-%d): ",currentplayer->id,currentplayer->cardinhand.height);
            if(total.a==1){
                number=demo_playcards(currentplayer,&(total.discard));
                played=(currentplayer->cardinhand.remain)[number-1];
            }
            else{
                if(scanf("%d",&number)){};
                played=(currentplayer->cardinhand.remain)[number-1];
                fg=checkIfFollowingCard(&played,&(total.discard));
                while (fg==1)
                {
                    printf("Input again(1-%d): ",currentplayer->cardinhand.height);
                    if(scanf("%d",&number)){};
                    played=(currentplayer->cardinhand.remain)[number-1];
                    fg=checkIfFollowingCard(&played,&(total.discard));
                }
            }
            fprint_card(&played,total.fd);fprintf(total.fd," \n");           
            cardAction(&total,&action,&played,currentplayer);
            change_cardinhand(&(currentplayer->cardinhand),number);
            put_to_deck(&played,&(total.discard));
            printf("Player %d cards: ",currentplayer->id);
            fprintf(total.fd,"Player %d cards: ",currentplayer->id);
            sort_deck(&(currentplayer->cardinhand));
            print_deck(&(currentplayer->cardinhand));
            fprint_deck(&(currentplayer->cardinhand),total.fd);
            //check if the game finishes
            result=isWin(currentplayer);
            if (result==0)
            {
                gocontinue(&currentplayer,&action);
                continue;
            }
            else
            {
                fprintf(total.fd,"Player %d wins!\n",currentplayer->id);
                printf("Round %d result:\n",i);
                fprintf(total.fd,"Round %d result:\n",i);
                end_the_round(n,&total);
                printf("Round %d ends.\n\n",i);
                fprintf(total.fd,"Round %d ends.\n\n",i);
                break;
            }
        }
        destroy_deck(&(total.discard));
        destroy_deck(&(total.stock));
        for(int j=0;j<n;j++)
            destroy_deck(&((total.player)[j].cardinhand));
    }
    printf("\nFinal scores: \n");
    fprintf(total.fd,"\nFinal scores: \n");
    for (int i = 0; i < n; i++)
    {
        printf("Player %d: %d\n",i+1,total.player[i].score);
        fprintf(total.fd,"Player %d: %d\n",i+1,total.player[i].score);
    }
    free(total.player);   
}
