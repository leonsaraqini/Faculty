#include<iostream>
#include <string.h>
using namespace std;

struct Player{
    char korisnickoIme[15];
    int nivo;
    int poeni;
};

struct ComputerGame{
    char ime[20];
    Player lista[30];
    int n;
};

void bestPlayer(ComputerGame *cg, int n){
    ComputerGame mostPopularGame = cg[0];

    for(int i = 0; i < n; i++){
        if(mostPopularGame.n < cg[i].n)
            mostPopularGame = cg[i];
    }

    int maxNumOfPoints = mostPopularGame.lista[0].poeni;
    int maxHighestLevel = mostPopularGame.lista[0].nivo;
    char playerName[15];

    strcpy(playerName, mostPopularGame.lista[0].korisnickoIme);

    for(int i = 0; i < mostPopularGame.n; i++){
        int numOfPoints = mostPopularGame.lista[i].poeni;
        int highestLevel = mostPopularGame.lista[i].nivo;

        if(numOfPoints > maxNumOfPoints || (numOfPoints == maxNumOfPoints && highestLevel > maxHighestLevel)){
            maxNumOfPoints = numOfPoints;
            maxHighestLevel = highestLevel;
            strcpy(playerName, mostPopularGame.lista[i].korisnickoIme);
        }
    }

    printf("Najdobar igrac e igracot so korisnicko ime %s koj ja igra igrata %s", playerName, mostPopularGame.ime);
}


int main() {
    int n,m;
    char ime[20];
    cin>>n;
    //create an array of max 100 computer games;
    ComputerGame poleigri[100];
    for (int i=0; i<n; i++) {
        ComputerGame nova;
        cin>>nova.ime>>nova.n;
        Player pole[30];
        for (int j=0; j<nova.n; j++) {
            Player nov;
            cin>>nov.korisnickoIme>>nov.nivo>>nov.poeni;
            nova.lista[j]=nov;
        }
        poleigri[i]=nova;
    }

    bestPlayer(poleigri,n);
    return 0;
}
