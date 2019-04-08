//player.cpp

#include "player.h"
#include <string>
#include <iostream>


using namespace std;

void Player::addCard(Card c) {
    myHand.push_back(c);
}
void Player::bookCards(Card c1,Card c2) {
    for(vector<Card>::iterator i = myHand.begin()-1;i!=myHand.end();++i) {
        for(vector<Card>::iterator j=i+1;j!=myHand.end();++j) {
            if(i->getRank()==j->getRank()) {    //pair, make add to book collection and recheck
                myBook.push_back(*i);
                myBook.push_back(*j);
                myHand.erase(i);
                myHand.erase(j);
                Player::bookCards(c1,c2);
                return;
            }
        }
    }
}
bool Player::rankInHand(Card c) const {
    for(int i =0; i<myHand.size();i++) {
        if(c.getRank()==myHand.at(i).getRank()) {
            return true;
        }
    }
    return false;
}
string Player::showHand() const {
    string out="";
    for(int i =0; i<myHand.size();i++) {
        out+=("["+myHand.at(i).toString()+"] ");
    }
    return out;
}
string Player::showBooks() const {
    string out="";
    for(int i =0; i<myBook.size();i+=2) {
        out+=("["+myBook.at(i).toString()+" "+myBook.at(i+1).toString()+"] ");
    }
    return out;
}
    
int Player::getHandSize() const {
    return myHand.size();
}
int Player::getBookSize() const {
    return myBook.size()/2;
} 