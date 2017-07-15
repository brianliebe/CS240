#include "Card.h"
#include <iostream>
#include <stdlib.h>

// Default constructor for Card, felt necessary for this to work when removing Queue and LL from Deck/Card.
Card::Card() {
}

// Constructor for Card, based on suit/value.
Card::Card(int newSuit, int newValue) {
	this->suit = newSuit;
	this->value = newValue;
}

// Overloaded operator for ==.
bool Card::operator == (const Card &other) {
	if (other.suit == this->suit && other.value == this->value) return true;
	return false;
}
