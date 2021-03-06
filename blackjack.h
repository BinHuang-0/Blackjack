#ifndef __BLACKJACK_H__
#define __BLACKJACK_H__

#include "deck.h"

class Blackjack {
    public:
        Blackjack();
        ~Blackjack();
        void startGame();

    private:
        Deck _deck;
        int _playerChips;

        int _playRound();
};

#endif