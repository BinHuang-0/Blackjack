#ifndef __DECK_H__
#define __DECK_H__

#include "card.h"
#include <random>
#include <time.h>

class Deck {
    public:
        Deck();
        ~Deck();
        void printDeck();
        void shuffle();
        Card draw();

    private:
        Card _deck[52];
        int _deckSize;

        void _shuffle();
        Card _draw();
};

#endif