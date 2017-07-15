#include "AntHill.h"
#include <iostream>
#include <stdlib.h>

using namespace std;

// Constructor without an ID
Ant::Ant() {
	id = -1;
	x = 0;
	y = 0;
}

// Constructor with an ID, and it's set.
Ant::Ant(int input_id) {
	x = 0;
	y = 0;
	id = input_id;
}

// Moves the ant based on a random int
void Ant::move() {
	int move_direction = rand() % 4 + 1;
	if (move_direction == 1) x++;
	if (move_direction == 2) x--;
	if (move_direction == 3) y++;
	if (move_direction == 4) y--;
}

// return the ID
int Ant::getID() {
	return id;
}

// return the X coordinate
int Ant::getX() {
	return x;
}

// return the Y coordinate
int Ant::getY() {
	return y;
}

// Constructor of the AntHill, taking in the max_ants
AntHill::AntHill(int max_ants_allowed) {
	max_ants = max_ants_allowed;
	next_id = 0;
	current_ants = 0;
}

// adds an ant, fails if it breaks the constraints of the hill. 
bool AntHill::addAnt() {
	if (next_id > 99) return false;
	if (next_id > max_ants - 1) return false;
	Ant newAnt = Ant(next_id);
	ants[next_id] = newAnt;
	next_id++;
	current_ants++;
	return true;
}

// returns an ant based on its ID
Ant AntHill::getAnt(int id) {
	Ant copy = ants[id];
	return copy;
}

// moves all of the ants at once
void AntHill::move() {
	int i;
	for (i = 0; i < next_id; i++) {
		ants[i].move();
	}
}

// changes the max number of ants allowed
bool AntHill::changeMax(int new_max) {
	if (new_max > 99) return false;
	if (new_max < 0) return false;
	max_ants = new_max;
	return true;
}

// prints out the relevant information about the hill.
void AntHill::printHillInfo() {
	int i;
	for (i = 0; i < next_id; i++) {
		cout << "Ant #" << ants[i].getID() << "[" <<  ants[i].getX() << "," << ants[i].getY() << "]" << endl;
	}
}

// return current number of ants
int AntHill::getCurrentNumAnts() {
	return current_ants;
}

// returns the max number of ants
int AntHill::getMaxAnts() {
	return max_ants;
}
