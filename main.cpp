#include "card.h"
#include "deck.h"
#include "blackjack.h"

int main(int argc, char* argv[]) {
    srand(time(NULL));

    Blackjack blackjack = Blackjack();
    blackjack.startGame();

    return 0;
}