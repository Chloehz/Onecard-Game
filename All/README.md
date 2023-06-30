# Onecard Game
## Information
### Personal Information
- Finished Date: 8th Nov. 2021

### Basic Information
- Project 2 is "onecard game" where at least two players could participate in. They could draw cards and play cards. Different cards with different ranks could have different actions. The first person having played all the cards in his hand wins, and others would receive scores equal to the numbers of cards remained in their hands. The game could have many rounds, and details of the entire game are stored in a document. Many parameters can be changed by command line instructions.
- Cards split into four main categories:
• Attack:
– Cards with rank 2: the next player draws two cards from the stock pile;
– Cards with rank 3: the next player draws three cards from the stock pile;
• Defense:
– Cards with rank 7: cancel an attack, i.e. do not draw any card if a 2 or a 3 was played before;
• Action:
– Queen cards: reverse the playing order from counter-clockwise to clockwise or clockwise to counterclockwise;
– Jack cards: skip the next player;
• Regular: any other card has no special effect and is only used to match the previous card’s rank or suit;
Notes on cards and attacks:
• The effect of the attack cards is cumulative.
• A Queen or a Jack, of same suit as the previous card, can be played to redirect an attack on the previous player,
or the player after the next one, respectively;
• When under an attack, a player not playing any special card (2, 3, 7, Q, J) must draw cards from the stock pile, and this ends his turn;

## Operations to Run the Project
- Open the terminal in the file HuangJiahe521370910102-p2.
- Input "make" in the command line. Then a "main.exe" is generated.
- Input "./main" in the command line, you could also add some other orders such as "-n 3"(to change the number of players to 3) after it. If input "-a" in the command line, the game would play a demo automatically. Then the game starts. All game details would be written into a log file(default: onecard.log). 
- In the real game, all hand card information is only visible to the corresponding player. When starting your turn, you may be asked to input '0'. Print '0' and press 'Enter' in the program to start your turn. 
- During the playing period, if the current player has a card to play, the program will prompt you with 1-n choices for the 1-n cards listed. Input a number among 1-n in the program. If a card is played improperly, the system will prompt you to play again. If the player has no card to play, he will draw 1 card from stock pile automatically.
- Once finishing dealing your own card, input '0' in the program and press "Enter" to clear the screen. 
- The game continues until the final round finishes.

## Bugs Remained
- No unsolved bug remained.

## Own Implement
### Initialization
- The total initialization is contained in the function "init_game.c", while single card initialization is contained in "card_init.c", deck in "init_deck.c". If there is no command line command, the system defaults to 4 players, 1 game, 2 deck, and all details are written in "onecard.log". While initializing, all cards would be placed into stock pile, where they would be shuffled(by exchanging two cards randomly for many times) and later given to everyone.

### Structures
There are five kinds of structures defined: card, deck, linklist, game, cardaction.
- card:
Structures to store the card suit(int suit from 1 to 4) and card rank(int num from 2 to 14).
Spades, Hearts, Diamonds, Clubs are represent by 1 to 4; Jack, Queen, King, Ace are 11 to 14.
- deck:
Structures to store the number of cards in the deck(int height from 0 to 52×d) and the cards in the deck(dynamic array: card pointer remain).
- linklist:
Structures to store the player related information, including player ID(int id from 1 to n), player scores(int score), players' hand-cards(deck cardinhand) and circular double linked list(linklist pointers pre and next).
- game:
Structures to store the necessary variables of the game, including stock pile(deck stock), discard pile(deck discard), players(dynamic array: linklist pointer player), if the game is played automatically(int a), the file to write the details in(FILE pointer fd).
- cardaction:
Structures to store the current cardactions, including the Clockwise or counterclockwise turn(int turn 1 or 0), the number of cards need to draw(int numToDraw), if the next player should be skipped(int isskip 0 or 1).

### Real Game Related
In the real game, in order to make sure the cards of the previous player would not be seen by others, two steps are included:
- Screen clear operation:
When finishing his turn, the current player should print '0' and press "Enter" to clear the screen. Then the current user of the computer would be changed.
- Turn start operation:
When starting his turn, the current player should print '0' and press "Enter" to start his turn. Then his cards in hand would be prompted.

## Simple Summary for Each File
### project.h
The header file defining all the structures and all the functions.

### main.c
The main function including command line function, dealing with the initial parameters and calling the "onecard" function.

### card.c
The file which contains all card directly-related functions.
- card_init function:
Initializing the card's rank and suit to 0.
- card_print function:
Printing the card, changing its rank and suit to strings(e.g. Spades 2).
- card_compare function:
Comparing two cards x1 and x2. Return 0 if x1 equals x2, 1 if x1>x2, 2 if x1< x2.

### deck.c
The file which contains all deck directly-related functions.
- init_deck function:
Initializing the deck's height to 0. Using malloc to initialize the dynamic array "(deck).remain".
- destroy_deck function:
Freeing the dynamic array "(deck).remain".
- draw_deck function:
Combining get_from_deck function and put_to_deck function together. Moving a card from one deck to another.
- exchange_deck function:
Changing two decks' "(deck).remain".
- get_from_deck function:
Getting a card from a deck.
- print_deck function:
Printing all the cards in the deck.
- put_to_deck function:
Putting a card to a deck.
- shuffle_deck function:
Shuffling all the cards in the deck by changing two cards randomly for many times.
- sort_deck function:
Changing the order of the cards in the deck. Sorting them using card_compare function.

### cardAction.c
The function which determines the actions need to take. 
If the rank of the played card is 2 or 3, 2 or 3 cards would be added to numToDraw.
If the rank is 7, clear numToDraw.
If the rank is 11, skip the next player.
If the rank is 12, change the turn.
If no special action is taken, draw the cards of corresponding number from the stock pile and print them.

### change_cardinhand.c
The function which changes the order of cards in the current player's hand after he played a card. Also reduce the height of his handcard deck.

### checkIfFollowingCard.c
The function which checks if the played card could follow the previous card. If so, return 0; else return 1.

### clear_screen.c
The function which clears the screen in real game, compatible with Windows, Linux and Apple.

### could_play.c
The function which checks if the current player could play a card matching the previous card using checkIfFollowingCard function. If not, draw 1 card for him automatically.

### demo_input0.c
The function which allows the program to move on even when playing the demo automatically. Using sleep() to make sure the game won't run too fast.

### demo_playcards.c
The function which allows the program to choose the first card from the current player's hand that matches the previous card when playing the demo automatically, print the card, and return the card order.

### end_the_round.c
The function which ends the round and prints the scores of each player.

### fprint_card.c
Similar to card_print function, print a single card into the opened log file.

### fprint_deck.c
Similar to print_deck function, print all the cards in the deck into the opened log file.

### gocontinue.c
The function which finds out who the next player is, and changes the currentplayer pointer to him.

### if_clear.c
The function which prompts the current computer user to clear the screen.

### init_game.c
The function which initializes the stock and discard decks. Check if the game would be played automatically as a demo. Put all the cards into the stock pile and shuffle them. Then initialize the players' structures, giving cards to them from the stock pile and sort the cards in their hands.

### isWin.c
The function which checks if the current player wins. If so, return 1; else return 0.

### onecard.c
The function used to concatenate subfunctions to build the body of the game. Free all the dynamic arrays and the end of each round and the end of the game.

### makefile
The makefile.

### Changelog.md
Store the changing details.
