//go_fish.cpp

#include "card.h"
#include "deck.h"
#include "player.h"
#include <iostream>
#include <fstream>

using namespace std;

void book(Player &p,int pn,ofstream &outFile) {
    Card c1,c2;
    while(p.checkHandForPair(c1,c2)) {
        outFile<<"Player "<<pn<< " books a pair of "<<c1.toString()[0]<<"'s."<<endl;
        p.bookCards(c1,c2);
    }
}
bool takeCards(Player &p1, Player &p2, Card c) {
    const int rank=c.getRank();
    bool result=false;
    for(int s=0;s<4;s++) {
        Card temp(rank,(Card::Suit)s);
        if(p2.cardInHand(temp)) {
            p2.removeCardFromHand(temp);
            p1.addCard(temp);
            result=true;
        }
    }
    return result;
}
int main(int argc,char*argv[]) {

    ofstream outFile;
    outFile.open("gofish_results.txt");


    Player p1("Player 1");
    Player p2("Player 2");
    Deck deck;
    deck.shuffle();

    //7 cards in starting hand
    for(int i=0;i<7;i++) {
        p1.addCard(deck.dealCard());
        p2.addCard(deck.dealCard());
    }
    
    Card picked;
    bool turn=true;

    //Main loop
    while((p1.getBookSize()+p2.getBookSize())<26) {
        //player 1's turn
        turn=true;
        while(turn&&p1.getHandSize()) {
            picked=p1.chooseCardFromHand();
            outFile<<"Player 1: Got any "<<picked.toString()[0]<<"'s?"<<endl;
            turn=takeCards(p1,p2,picked);
            if(turn)
                outFile<<"Player 2: Yes. "<<endl;
            
        }
        //out of loop, fish
        outFile<<"Player 2: Go Fish."<<endl;
        if(deck.size()) {
            p1.addCard(deck.dealCard());
        }
        book(p1,1,outFile);

        //player 2's turn
        outFile<<endl;
        turn=true;
        while(turn&&p2.getHandSize()) {
            picked=p2.chooseCardFromHand();
            outFile<<"Player 2: Got any "<<picked.toString()[0]<<"'s?"<<endl;
            turn=takeCards(p2,p1,picked);
            if(turn)
                outFile<<"Player 1: Yes. "<<endl;  
        }
        //out of loop, fish
        outFile<<"Player 1: Go Fish."<<endl;
        if(deck.size()) {
            p2.addCard(deck.dealCard());
        }
        book(p2,2,outFile);
        outFile<<endl;
    }
    outFile<<"Player 1 has "<<p1.getBookSize()<<" books"<<endl;
    outFile<<"Player 2 has "<<p2.getBookSize()<<" books"<<endl;
    if(p1.getBookSize()>p2.getBookSize())
        outFile<<"Player 1 wins."<<endl;
    else if(p1.getBookSize()<p2.getBookSize())
        outFile<<"Player 2 wins."<<endl;
    else
        outFile<<"Tie game."<<endl;
    
}