#ifndef DECK_H
#define DECK_H

#include "Card.h"
#include <vector>

class Deck {
	//friend class Queue<T>;
	//friend class LinkedList<T>;
	friend class Card;
	private:
		std::vector<Card> deck;
	public:
		Deck();
		Card draw();
		bool empty();
		void shuffle();
		bool emptyArray(int array[52]);
};

#endif
