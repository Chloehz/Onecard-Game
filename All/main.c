#include "project.h"

int main(int argc, char *argv[]){
    int n=4;int c=5;int d=2;int r=1;int a=0;char *file="onecard.log";
    int opt;
    char* const short_options="hn:c:d:r:a";
    static struct option long_options[] = 
    {
        {"help",no_argument,NULL,'h'},
        {"player-number",required_argument,NULL,'n'},
        {"initial-cards",required_argument,NULL,'c'},
        {"decks",required_argument,NULL,'d'},
        {"rounds",required_argument,NULL,'r'},
        {"auto",no_argument,NULL,'a'},
        {"log",required_argument,NULL,'f'},
        {0,0,0,0}
    };

    while((opt = getopt_long(argc,argv,short_options,long_options, NULL))!=-1)
    {
        switch (opt) {
            case 'h':
                printf("-h|--help               print this help message!\n");
                printf("--log filename          write the logs in filename (default: onecard.log)\n");
                printf("-n n|--player-number=n  n players, n must be larger than 2 (default: 4)\n");
                printf("-c c|--initial-cards=c  deal c cards per player, c must be at least 2 (default: 5)\n");
                printf("-d d|--decks=d          use d decks 52 cards each, d must be at least 2 (default: 2)\n");
                printf("-r r|--rounds=r         play r rounds, r must be at least 1 (default: 1)\n");
                printf("-a|--auto               run in demo mode\n");
                break;
            case 'n':
                n=(optarg==NULL?4:atoi(optarg));
                printf("The number of players: %d\n",n);
                break;
            case 'c':
                c=(optarg==NULL?5:atoi(optarg));
                printf("The number of initial cards per player: %d\n",c);
                break;
            case 'd':
                d=(optarg==NULL?2:atoi(optarg));
                printf("The number of decks: %d\n",d);
                break;
            case 'r':
                r=(optarg==NULL?1:atoi(optarg));
                printf("The number of rounds: %d\n",r);
                break;
            case 'f':
                file=(optarg==NULL?"onecard.log":optarg);
                printf("Write the logs in %s\n",file);
                break;
            case 'a':
                a=1;
                printf("The game will run in demo mode.\n");
                break;
        }
    }
    FILE *fd;
    fd=fopen(file,"w+");
    onecard(c,n,d,r,a,fd);
    fclose(fd);
    return 0;
}
