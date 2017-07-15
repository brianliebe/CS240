#include "Player.h"
#include <iostream>

#include <string>

using namespace std;

// Default constructor for Player, I found it was necessary for limiting heap usage by eliminating Queue and LL.
// It, clearly, doesn't actually do anything.
Player::Player() {
}

// Constructor for Player, takes a string & int and sets them as the name and budget.
Player::Player(string name, int budget) {
	this->name = name;
	this->budget = budget;
}

// returns the player's name
string Player::getName() {
	return name;
}

// returns the players budget
int Player::getBudget() {
	return budget;
}

// removes the amount of money from the player's budget.
bool Player::bet(int amount) {
	if (amount > budget) return false;
	else budget -= amount;
	return true;
}

// adds the amount into the player's budget.
void Player::collectWinnings(int amount) {
	budget += amount;
}
