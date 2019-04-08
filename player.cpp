//player.cpp

#include "player.h"
#include <string>
#include <iostream>
#include <ctime>

using namespace std;

void Player::addCard(Card c) {
    myHand.push_back(c);
}
void Player::bookCards(Card c1,Card c2) {
    myBook.push_back(c1);
    myBook.push_back(c2);
    for(vector<Card>::iterator i = myHand.begin();i!=myHand.end();++i) {
        if(*i==c1) {
            myHand.erase(i);
            i--;
        }
        if(*i==c2) {
            myHand.erase(i);
            i--;
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
Card Player::removeCardFromHand(Card c) {
    for(vector<Card>::iterator i = myHand.begin();i!=myHand.end();++i) {
        if(c==*i) {
            myHand.erase(i);
            return c;
        }
    }
}
bool Player::cardInHand(Card c) const {
    for(int i=0;i<myHand.size();i++) {
        if(c.toString()==myHand[i].toString())
            return true;
    }
    return false;
}
Card Player::chooseCardFromHand() const {
    int picked=rand()%myHand.size();
    return myHand[picked];
}
bool Player::checkHandForPair(Card &c1, Card &c2) {
    for(int i =0;i<myHand.size()-1;i++) {
        for(int j=i+1;j<myHand.size();j++) {
            if(myHand[i].getRank()==myHand[j].getRank()) {
                c1=myHand[i];
                c2=myHand[j];
                return true;
            }
        }
    }
    return false;
}