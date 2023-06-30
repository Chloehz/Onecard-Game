#ifndef PROJECT_H
#define PROJECT_H

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <getopt.h>
#include <time.h>
#include <unistd.h>

typedef struct card_
{
    int suit;
    int num;
    //int numintotal;
}card;

typedef struct deck_
{
    int height;//height of the deck
    card *remain;
}deck;

typedef struct linklist_
{
    int id;
    int score;
    deck cardinhand;
    struct linklist_ *pre,*next;
}linklist;

typedef struct game_
{
    deck stock;
    deck discard;
    linklist *player;
    int a;
    FILE *fd;
}game;

typedef struct cardaction_
{
    int turn;
    int numToDraw;
    int isskip;
}cardaction;



//functions defined:

//card
void card_init(card* x);
void card_print(card* x);
int  card_compare(card* x1, card* x2);
//deck
void destroy_deck(deck *x);
void draw_deck(deck *x, deck *y); //draw a card from x to y
void exchange_deck(deck *x, deck *y); //exchange x and y
void get_from_deck(deck *x, card *y); //draw y from x
void init_deck(deck *x, int d);
void print_deck(deck *x);
void put_to_deck(card *x,deck *y);//put x to y
void shuffle_deck(deck *x);       //shuffle x
void sort_deck(deck *x);
//onecardgame
void cardAction(game *total, cardaction *action, card *played, linklist *currentplayer);
int checkIfFollowingCard(card *currentCard, deck *discard);
int could_play(linklist *currentplayer, game *total);
void gocontinue(linklist **currentplayer, cardaction *action);
void init_game(int n, int c, int d, int r, int a, FILE *fd, game *total);
int isWin(linklist *currentplayer);
void onecard(int c, int n, int d, int r,int a,FILE *fd);
void change_cardinhand(deck *x,int number);
void end_the_round(int n,game *total);
//find the system
void clear_screen();
//demo related
int demo_input0(game *total);
void if_clear(game *total);
int demo_playcards(linklist *currenplayer,deck *discard);
//log related
void fprint_card(card* x,FILE *fd);
void fprint_deck(deck *x,FILE *fd);

#endif
