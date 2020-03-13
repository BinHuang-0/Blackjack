#include "blackjack.h"

Blackjack::Blackjack() {
    _deck = Deck();
    _deck.shuffle();

    _playerChips = 50;
}

Blackjack::~Blackjack() {

}

void Blackjack::startGame() {
    int gameState = 0;
    cout << "Welcome to Bin's Blackjack" << endl;
    while(_playerChips > 0 && gameState == 0) {
        gameState = _playRound();
    }
    
}

//need to add functionality to this
//if return is 0, stop playing
int Blackjack::_playRound() {
    int playerChoice;
    Card playerHand[10];
    Card dealerHand[10];
    int handSize = 0;
    int dealerSize = 0;
    int dealerScore = 0;
    int playerScore = 0;

    int playerBet = 0;
    cout << "You currently have " << _playerChips << " chips." << endl;

    //player bets
    cout << "Place your bets" << endl;
    cin >> playerBet;
    if(playerBet < 0) {
        cout << "You leave with " << _playerChips << " chips" << endl;
        return 1;
    }
    else if (playerBet == 0) {
        cout << "You must place a bet" << endl;
        return 0;
    }
    //check if player has bet more than they have
    else if(playerBet > _playerChips) {
        cout << "Not enough chips" << endl;
        return 0;
    }
    //deal hand
    else {
        //player gets cards
        playerHand[handSize++] = _deck.draw();
        playerHand[handSize++] = _deck.draw();

        playerScore = playerHand[0].getValue() + playerHand[1].getValue();
        cout << "Your current score is: " << playerScore << endl;

        //player hits, stays, 
        //splits to be implemented
        cout << "1: hit     2: stay" << endl;
        cin >> playerChoice;
        while(playerChoice == 1) {
            playerHand[handSize++] = _deck.draw();
            playerScore += playerHand[handSize - 1].getValue();
            //check if over
            if(playerScore > 21)
                playerChoice = 0;
            else {
                cout << "Your cards are: " << endl;
                for(int i = 0; i < handSize; i++) {
                    playerHand[i].printCard();
                }
                cout << endl;
                cout << "Your current score is: " << playerScore << endl;
                cout << "1: hit     2: stay" << endl;
                cin >> playerChoice;
            }
        }

        //dealer plays
        //dealer draws cards
        dealerHand[dealerSize++] = _deck.draw();
        dealerHand[dealerSize++] = _deck.draw();

        dealerScore = dealerHand[0].getValue() + dealerHand[1].getValue();
        while(dealerScore <= playerScore && dealerScore < 21) {
            dealerHand[handSize++] = _deck.draw();
            dealerScore += dealerHand[handSize - 1].getValue();
        }

        cout << "Dealer's score: " << dealerScore << endl;
        cout << "Your score: " << playerScore << endl;

        if(playerScore > 21)
            _playerChips -= playerBet;
        else if(dealerScore > 21)
            _playerChips += playerBet;
        else if(playerScore < dealerScore)
            _playerChips -= playerBet;
        else
            _playerChips += playerBet;
    }

    return 0;
}