#include "Deck.h"
#include "Card.h"
#include <iostream>
#include <stdlib.h>

// Contructor for Deck. Initializes a Queue, and then enqueues 52 cards into the deck.
Deck::Deck() {
	deck = new Queue<Card*>();
	int suitsLeft = 4;
	int cardsLeft = 14;
	while (suitsLeft) {
		while (cardsLeft > 1) {
			Card * temp = new Card(suitsLeft, cardsLeft);
			deck->enqueue(temp);
			cardsLeft--;
		}
		cardsLeft = 14;
		suitsLeft--;
	}
}

// Draws a card from deck and then deletes that card. The deck is deleted if it's the last card in the deck.
Card Deck::draw() {
	Card * tempCard = (deck->dequeue());
	Card copy = *(tempCard);
	delete tempCard;
	if (empty()) {
		delete deck;
		deck = NULL;
	}
	return copy;
}

// Checks to see if the deck is empty or not.
bool Deck::empty() {
	if (deck == NULL || deck->empty()) {
		return true;
	}
	return false;
}

// Checks for emptiness in the temporary array used in Shuffle. Just a helper function.
bool Deck::emptyArray(int array[52]) {
	bool done = true;
	for (int i = 0; i < 52; i++) {
		if(array[i] == 0) {
			done = false;
		}
	}
	return done;
}

// First, it creates a list of all of the drawn cards in deck.
// Then it creates an empty integer array full of 0's.
// Lastly, a random number is called and that number from the list array will be enqueued back into the deck.
void Deck::shuffle() {
	Card * list[52];
	for (int i = 0; i < 52; i++) {
		Card temp = draw();
		list[i] = new Card(temp.getSuit(), temp.getValue());
	}
	deck = new Queue<Card*>();
	int called[52];
	for (int i = 0; i < 52; i++) called[i] = 0;
	while (!emptyArray(called)) {
		bool found = false;
		int random = rand() % 52 + 1;
		for (int i = 0; i < 52; i++) {
			if (called[random-1] == 1) found = true;
		}
		if (!found) {
			deck->enqueue(list[random-1]);
			called[random-1] = 1;
		}
	}
}
