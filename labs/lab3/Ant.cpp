#include "Ant.h"
#include "AntHill.h"
#include <iostream>
#include <stdlib.h>

using namespace std;

// Constructor with an ID, and it's set.
Ant::Ant(int input_id) {
	x = 0;
	y = 0;
	id = input_id;
	experience = rand() % 20 + 1;
}

// Moves the ant based on a random int
void Ant::move() {
	int move_direction = rand() % 4 + 1;
	if (move_direction == 1) x++;
	if (move_direction == 2) x--;
	if (move_direction == 3) y++;
	if (move_direction == 4) y--;
}

/* Each ant starts with a random Exp, 1-20. If they're even, it's a 50% chance. Otherwise, a percentage
 * chance comes from the exp / total experience. This become a percentage (1-100) and then a random roll
 * is made 1-100 to see if it hits P1 or P2. I.E. 15 exp vs 5 sxp means P1 has a 75% chance of winning.
 * If a roll of 1-75 is made, P1 wins. Otherwise, P2 wins. All exp goes to the winning ant.
 */
Ant * Ant::fight(Ant * challenger) {
	double exp1 = this->getExp() + 0.0;
	double exp2 = challenger->getExp() + 0.0;
	double totalExp = exp1 + exp2;
	double chance = exp1 / totalExp * 100;
	// cout << endl;
	if (exp1 == exp2) {
		int roll = rand() % 2 + 1;
		if (roll == 1) {
			this->setExp(this->getExp() + challenger->getExp());
			cout << "Player 1 Wins! New Exp: " << this->getExp() << endl;
			return this;
		}
		else {
			challenger->setExp(this->getExp() + challenger->getExp());
			cout << "Player 2 Wins! New Exp: " << challenger->getExp() << endl;
			return challenger;
		}
	}
	int roll = rand() % 100 + 1;
	if (roll >= chance) {
		// cout << "Chance: " << chance << " Roll: " << roll << endl;
		challenger->setExp(this->getExp() + challenger->getExp());
		cout << "Player 2 Wins! New Exp: " << challenger->getExp() << endl;
		return this;
	}
	// cout << "Chance: " << chance << " Roll: " << roll << endl;
	this->setExp(this->getExp() + challenger->getExp());
	cout << "Player 1 Wins! New Exp: " << this->getExp() << endl;
	return challenger;
}
