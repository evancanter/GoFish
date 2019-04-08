// FILE: card_demo.cpp
// This is a small demonstration program showing how the Card and Deck classes are used.
#include <iostream>    // Provides cout and cin
#include <cstdlib>     // Provides EXIT_SUCCESS
#include "card.h"
#include "player.h"
#include "deck.h"

using namespace std;


// PROTOTYPES for functions used by this demonstration program:
//void dealHand(Deck &d, Player &p, int numCards);


/*t

int main( )
{
    int numCards = 5;
    
    Player p1("Joe");
    Player p2("Jane");
    
    Deck d;  //create a deck of cards
    d.shuffle();
    
    dealHand(d, p1, numCards);
    dealHand(d, p2, numCards);
       
    cout << p1.getName() <<" has : " << p1.showHand() << endl;
    cout << p2.getName() <<" has : " << p2.showHand() << endl;
    
    return EXIT_SUCCESS;  
}
*/
int main() {
    Card::Suit d=Card::diamonds;

    Card c1;
    Card c2(12,d);
    cout<<"c1: "<<c1.toString()<<endl;
    cout<<"c2: "<<c2.toString()<<endl;
    Deck deck;
    Card c3;
    cout<<"Size: "<<deck.size()<<endl;
    for(int i =0;i<52;i++) {
        c3=deck.dealCard();
        cout<<deck.size()<<": "<<c3.toString()<<endl;
    }
    deck.shuffle();
    cout<<"SHUFFLED"<<endl;
    for(int i =0;i<52;i++) {
        c3=deck.dealCard();
        cout<<deck.size()<<": "<<c3.toString()<<endl;
    }
}

/*
void dealHand(Deck &d, Player &p, int numCards)
{
   for (int i=0; i < numCards; i++)
      p.addCard(d.dealCard());
}
*/
   



