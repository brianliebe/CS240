#ifndef CARD_H
#define CARD_H

class Card {
	private:
		int suit;
		int value;
	public:
		Card();
		Card(int suit, int value);
		inline int getValue() { return value; }
		inline int getSuit() { return suit; }
		bool operator == (const Card &other);
};

#endif
