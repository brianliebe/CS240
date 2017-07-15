#include "Card.h"
#include <iostream>
#include <stdlib.h>

// Constructor for Card. No default, just based on suit/value.
Card::Card(int newSuit, int newValue) {
	this->suit = newSuit;
	this->value = newValue;
}

// Overloaded operator for ==.
bool Card::operator == (const Card &other) {
	if (other.suit == this->suit && other.value == this->value) return true;
	return false;
}
