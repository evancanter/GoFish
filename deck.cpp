//deck.cpp


#include "deck.h"
#include <string>
#include <iostream>
#include "card.h"
#include <ctime>
#include <cstdlib>

using namespace std;

Deck::Deck() {
    time_t timer;
    myIndex=0;
    int count=0;
    for(int i =1;i<=4;i++) {
        Card::Suit s;
        switch(i) {
            case 1:
                s=Card::spades;
                break;
            case 2:
                s=Card::diamonds;
                break;
            case 3:
                s=Card::clubs;
                break;
            case 4:
                s=Card::hearts;
            default:
                break;
        }
        for(int j=1;j<=13;j++) {
            Card c(j,s);
            myCards[count++]=c;
        }
    }
    srand(time(&timer));
}
int Deck::size() const {
    return 52-myIndex;
}
Card Deck::dealCard() {
    return myCards[myIndex++];
}
void Deck::shuffle() {
    int rI;
    for(int i =0;i<52;i++) {
        rI=rand()%52;
        //swap i and rI
        Card temp=myCards[i];
        myCards[i]=myCards[rI];
        myCards[rI]=temp;
    }
    myIndex=0;
}