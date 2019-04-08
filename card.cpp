//card.cpp

#include <iostream>
#include <string>
#include "card.h"

using namespace std;

Card::Card() {
    myRank=1;
    mySuit=spades;
}
Card::Card(int rank, Suit s) {
    myRank=rank;
    mySuit=s;
}
Card::Card(Card const &c) {
    myRank=c.myRank;
    mySuit=c.mySuit;
}
string Card::rankString(int r) const {
        switch(r) {
            case 1:
                return "A";
                break;
            case 2:
                return "2";
                break;
            case 3:
                return "3";
                break;
            case 4:
                return "4";
                break;
            case 5:
                return "5";
                break;
            case 6:
                return "6";
                break;
            case 7:
                return "7";
                break;
            case 8:
                return "8";
                break;
            case 9:
                return "9";
                break;
            case 10:
                return "10";
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

bool Card::operator ==(Card const &c) const {
    return myRank == c.getRank() && mySuit==c.mySuit;
}
bool Card::operator !=(Card const &c) const {
    return !(myRank == c.getRank() && mySuit==c.mySuit);
}