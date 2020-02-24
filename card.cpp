#include "card.h"

Card::Card() {
    this->_value = 0;
    this->_suit = DIAMOND;
}

Card::Card(int value, Suit suit) {
    this->_value = value;
    this->_suit = suit;
}

Card::~Card() {

}

int Card::getValue() {
    return this->_value;
}

Suit Card::getSuit() {
    return this->_suit;
}

void Card::printCard() {
    string printValue = "";

    switch(this->_value) {
        case 1:
            printValue.append("Ace");
            break;
        case 11:
            printValue.append("Jack");
            break;
        case 12:
            printValue.append("Queen");
            break;
        case 13:
            printValue.append("King");
            break;
        default:
            printValue.append(to_string(this->_value));
            break;
    }

    printValue.append(" of ");

    switch(this->_suit) {
        case DIAMOND:
            printValue.append("Diamonds");
            break;
        case CLUB:
            printValue.append("Clubs");
            break;
        case HEART:
            printValue.append("Hearts");
            break;
        case SPADE:
            printValue.append("Spades");
            break;
    }

    cout << printValue << endl;
}