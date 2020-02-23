#include "card.h"

Card::Card() {
    this->value = 0;
    this->suit = DIAMOND;
}

Card::Card(int value, Suit suit) {
    this->value = value;
    this->suit = suit;
}

Card::~Card() {

}

int Card::getValue() {
    return this->value;
}

Suit Card::getSuit() {
    return this->suit;
}

void Card::printCard() {
    string printValue = "";

    switch(this->value) {
        case 1:
            printValue.append("Ace");
            break;
        case 10:
            printValue.append("Jack");
            break;
        case 11:
            printValue.append("Queen");
            break;
        case 12:
            printValue.append("King");
            break;
        default:
            printValue.append(to_string(this->value));
            break;
    }

    printValue.append(" of ");

    switch(this->suit) {
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