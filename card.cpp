//card.cpp

#include <iostream>
#include <string>
#include "card.h"

using namespace std;

Card::Card() {
    myRank=1;
    mySuit=Suit::spades;
}
Card::Card(int rank, Suit s) {
    myRank=rank;
    mySuit=s;
}
string Card::rankString(int r) const {
    if(r>1 && r < 11)
        return r+"";
    else {
        switch(r) {
            case 1:
                return "A";
                break;
            case 11:
                return "J";
                break;
            case 12:
                return "Q";
                break;
            case 13:
                return "K";
                break;
            default:
                break;
        }
    }
   return "invalid rank"; 
}
string Card::suitString(Suit s) const {
    switch(s) {
        case diamonds:
            return "d";
            break;
        case hearts:
            return "h";
            break;
        case clubs:
            return "c";
            break;
        case spades:
            return "s";
            break;
        default:
            break;
    }
    return "suitString Error";
}
string Card::toString() const {
    return rankString(myRank)+suitString(mySuit);
}
bool Card::sameSuitAs(Card const &c) const {
    return toString()[1]==c.toString()[1];
}
int Card::getRank() const {
    return myRank;
}
