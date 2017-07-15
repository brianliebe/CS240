#include "Ant.h"
#include "AntHill.h"
#include <iostream>
#include <stdlib.h>
#include <cstring>

using namespace std;

// Constructor of the AntHill, taking in the max_ants
AntHill::AntHill() {
	// max_ants = max_ants_allowed;
	next_id = 0;
	current_ants = 0;
	ants = NULL;
}
// Destructor for AntHill, deletes all individual ants and the ant array.
AntHill::~AntHill() {
	for (int i = 0; i < current_ants; i++) {
		delete ants[i];
	}
	delete[] ants;
}

// adds an ant by creating a new ant array and replacing.
int AntHill::addAnt() {
	Ant ** copy = new Ant*[current_ants + 1];
	if (ants != NULL) {
		for (int i = 0; i < current_ants; i++) {
			copy[i] = ants[i];
		}
	}
	copy[current_ants] = new Ant(next_id);

	next_id++;
	current_ants++;
	delete[] ants;
	ants = copy;
	return next_id - 1;
}

// removes an ant by creating a new ant array and replacing
bool AntHill::removeAnt(int input_id) {
	if (input_id < 0) return false;
	Ant ** copy = new Ant*[current_ants - 1];
	bool done = false;
	for (int i = 0; i < current_ants; i++) {
		if (ants[i]->getID() == input_id) {
			delete ants[i];
			done = true;
		}
		else {
			if (done) copy[i - 1] = ants[i];
			else copy[i] = ants[i];
		}
	}
	current_ants--;
	delete[] ants;
	ants = copy;
	return true;
}

// returns an ant based on its ID
Ant * AntHill::getAnt(int input_id) {
	Ant * copy;
	for (int i = 0; i < current_ants; i++) {
		if (ants[i]->getID() == input_id) {
			copy = ants[i];
			return copy;
		}
	}
	return NULL;
}

// moves all of the ants at once
void AntHill::move() {
	int i;
	for (i = 0; i < current_ants; i++) {
		ants[i]->move();
	}
}

// prints out the relevant information about the hill.
void AntHill::printHillInfo() {
	int i;
	for (i = 0; i < current_ants; i++) {
		cout << "Ant #" << ants[i]->getID() << "[" <<  ants[i]->getX() << "," << ants[i]->getY() << "]" << endl;
	}
}

