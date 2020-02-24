#ifndef __CARD_H__
#define __CARD_H__

#include <iostream>
#include <string>

using namespace std;

enum Suit {
    DIAMOND,
    CLUB,
    HEART,
    SPADE
};

class Card {
    public:
        Card();
        Card(int, Suit);
        ~Card();
        int getValue();
        Suit getSuit();
        void printCard();

    private:
        int _value;
        Suit _suit;

};

#endif