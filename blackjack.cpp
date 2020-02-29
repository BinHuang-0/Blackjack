#include "blackjack.h"

Blackjack::Blackjack() {
    _deck = Deck();
    _deck.shuffle();

    _dealerScore = 0;
    _playerChips = 50;
    _playerScore = 0;
}

Blackjack::~Blackjack() {

}

void Blackjack::startGame() {
    int gameState = 1;
    cout << "Welcome to Bin's Blackjack" << endl;
    while(_playerChips > 0 && gameState != 0) {
        gameState = _playRound();
    }
    
}

//need to add functionality to this
//if return is 0, stop playing
int Blackjack::_playRound() {
    int playerBet = 0;
    cout << "You currently have " << _playerChips << " chips." << endl;

    //player bets
    cout << "Place your bets" << endl;
    cin >> playerBet;
    if(playerBet < 0) {
        cout << "You leave with " << _playerChips << " chips" << endl;
        return 0;
    }
    else if (playerBet == 0) {
        cout << "You must place a bet" << endl;
        return 1;
    }
    //check if player has bet more than they have
    else if(playerBet < _playerChips) {
        cout << "Not enough chips" << endl;
        return 1;
    }
    //deal hand
    else {

    }

    //player gets cards
    //player hits, stays, or splits


    return 0;
}