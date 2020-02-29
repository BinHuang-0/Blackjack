IDIR=/home/manperson/Desktop/Blackjack
CC=g++
CCFLAGS=-I$(IDIR) -g

OBJS=card.o deck.o blackjack.o

Blackjack: main.cpp $(OBJS)
	$(CC) -o $@ $^ $(CCFLAGS)

card.o: card.cpp card.h
	$(CC) -c -o $@ $< $(CCFLAGS)

deck.o: deck.cpp deck.h
	$(CC) -c -o $@ $< $(CCFLAGS)

blackjack.o: blackjack.cpp blackjack.h
	$(CC) -c -o $@ $< $(CCFLAGS)

.PHONY: clean

clean:
	rm $(OBJS) Blackjack