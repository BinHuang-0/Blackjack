#include "deck.h"

Deck::Deck() {
    for(int i = 1; i <= 13; i++) {
        _deck[(i - 1) * 4] = Card(i, DIAMOND); 
        _deck[(i - 1) * 4 + 1] = Card(i, CLUB); 
        _deck[(i - 1) * 4 + 2] = Card(i, HEART); 
        _deck[(i - 1) * 4 + 3] = Card(i, SPADE); 
    }
    _deckSize = 52;
}

Deck::~Deck() {

}

void Deck::printDeck() {
    for(int i = 0; i < _deckSize; i++) {
        _deck[i].printCard();
    }
}

void Deck::shuffle() {
    _shuffle();
}

Card Deck::draw() {
    return _draw();
}

void Deck::_shuffle() {
    int rnd;
    Card tmp;
    for(int i = 51; i >= 0; i--) {
        rnd = rand() % (i + 1);
        tmp = _deck[rnd];
        _deck[rnd] = _deck[i];
        _deck[i] = tmp;
    }
    _deckSize = 52;
}

Card Deck::_draw() {
    return _deck[--_deckSize];
}