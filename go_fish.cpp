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
        outFile<<"Player "<<pn<< " books a pair of "<<c1.rankString(c1.getRank())<<"'s."<<endl;
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
        if((p1.getBookSize()+p2.getBookSize())<26) {
            outFile << "Player 1's hand: " <<p1.showHand() <<endl << "Player 2's hand: "<<p2.showHand()<<endl;
            turn=true;
            while(turn&&p1.getHandSize()) {
                picked=p1.chooseCardFromHand();
                if(p2.getHandSize())
                    outFile<<"Player 1: Got any "<<picked.rankString(picked.getRank())<<"'s?"<<endl;
                turn=takeCards(p1,p2,picked);
                if(turn)
                    outFile<<"Player 2: Yes. "<<endl;
                
            }
            //out of loop, fish
            if(deck.size()) {
                outFile<<"Player 2: Go Fish."<<endl;
                p1.addCard(deck.dealCard());
            }
            book(p1,1,outFile);     
        }
        outFile<<endl;

        //player 2's turn
        
       
        if((p1.getBookSize()+p2.getBookSize())<26) {
            outFile << "Player 1's hand: " <<p1.showHand() <<endl << "Player 2's hand: "<<p2.showHand()<<endl;
            turn=true;
            while(turn&&p2.getHandSize()) {
                picked=p2.chooseCardFromHand();
                if(p1.getHandSize())
                    outFile<<"Player 2: Got any "<<picked.rankString(picked.getRank())<<"'s?"<<endl;
                turn=takeCards(p2,p1,picked);
                if(turn)
                    outFile<<"Player 1: Yes. "<<endl;  
            }
            //out of loop, fish
            
           
            if(deck.size()) {
                outFile<<"Player 1: Go Fish."<<endl;
                p2.addCard(deck.dealCard());
            }
            book(p2,2,outFile);
        }
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