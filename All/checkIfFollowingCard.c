#include "project.h"

int checkIfFollowingCard(card *currentCard,deck *discard){
    int nxtSuit=(discard->remain)[discard->height-1].suit;//discard.height-1 when using dynamic
    int nxtNum=(discard->remain)[discard->height-1].num;//take Jack, Queen, King, Ace as 11,12,13,14
    return currentCard->suit!=nxtSuit&&currentCard->num!=nxtNum;
}
