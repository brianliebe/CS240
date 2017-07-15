#ifndef CARD_H
#define CARD_H

#include "Queue.h"
#include "LinkedList.h"

class Card {
	friend class Queue<Card*>;
	friend class LinkedList<Card*>;
	private:
		int suit;
		int value;
	public:
		Card(int suit, int value);
		inline int getValue() { return value; }
		inline int getSuit() { return suit; }
		bool operator == (const Card &other);
};

#endif
