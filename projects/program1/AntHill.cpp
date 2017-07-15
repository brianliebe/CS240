#include "Ant.h"
#include "AntHill.h"
#include "LinkedList.h"
#include <iostream>
#include <stdlib.h>
#include <cstring>
#include <fstream>
#include <string>

#define GRIDMAX 4

using namespace std;

// Constructor of the AntHill, taking in the max_ants
AntHill::AntHill() {
	file.open("anthill.log");
	antActions = "";
	won = lost = attacked = 0;
	turn_num = 1;
	list = new LinkedList();
	list->insertAnt(new Ant(0));
	list->insertAnt(new Ant(1));
	list->insertAnt(new Ant(2));
	food = 0;
	next_id = 0;
	current_ants = 0;
	ants = NULL;
	addAnt();
	addAnt();
	addAnt();
	maxX = GRIDMAX;
	maxY = GRIDMAX;
}

// Destructor for AntHill, deletes all individual ants and the ant array.
AntHill::~AntHill() {
	for (int i = 0; i < current_ants; i++) {
		delete ants[i];
	}
	delete[] ants;
	delete list;
	file.close();
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
		int move = ants[i]->move(maxX, maxY);
		if (move == 0) {
			string sent = "    Ant #" + to_string(ants[i]->getID()) + " has run into a rival ant and has won the fight.\n";
			antActions.append(sent);
		}
		if (move == 1) {
			string sent = "    Ant #" + to_string(ants[i]->getID()) + " has run into a rival ant and loses the fight and dies.\n";
			antActions.append(sent);
			if (current_ants < 100) {
				if (current_ants != 0) {
					list->removeAnt(ants[i]->getID());
					removeAnt(ants[i]->getID());
				}
			}
		}
		if (move == 2) {
			food++;
		}
		if (move == 3) {
			//nothing
		}
	}
}

// prints out the relevant information about the hill.
void AntHill::printHillInfo() {
	int i;
	for (i = 0; i < current_ants; i++) {
		cout << "Ant #" << ants[i]->getID() << "[" <<  ants[i]->getX() << "," << ants[i]->getY() << "]" << endl;
	}
}

// prints the farm's relevant information to the file
void AntHill::printFarmInfo() {
	file << "    ================== Turn #" << turn_num << " ==================" << endl;
	file << "The hill currently has:" << endl;
	file << "    Food: " << food << endl;
	file << "    Ants: " << current_ants << endl;
	file << "The hill has been attacked " << attacked << " times." << endl;
	file << "    Successfully defended: " << won << endl;
	file << "    Failed to defend: " << lost << endl;
	file << "Summary: " << endl;
}

// calls a turn for the farm, including wars (and per ant battles) and adds new ants.
void AntHill::turn() {
	int somethingToPrint = 0;
	move();
	printFarmInfo();
	file << antActions;
	antActions = "";
	if (current_ants) {
		int random = rand() % 5 + 1;
		if (random == 5) {
			attacked++;
			int attackers = rand() % (current_ants) + 1;
			int defenders = 0;
			for (int i = 0; i < current_ants; i++) {
				if (ants[i]->getX() > (GRIDMAX/2 * (-1)) && ants[i]->getX() < (GRIDMAX/2)) {
					if (ants[i]->getY() > (GRIDMAX/2 * (-1)) && ants[i]->getY() < (GRIDMAX/2)) {
						defenders++;
					}
				}
			}
			if (attackers > defenders) {
				for (int i = 0; i < current_ants; i++) {
					if (ants[i]->getX() > (GRIDMAX/2 * (-1)) && ants[i]->getX() < (GRIDMAX/2)) {
						if (ants[i]->getY() > (GRIDMAX/2 * (-1)) && ants[i]->getY() < (GRIDMAX/2)) {
							if (current_ants != 0) {
								somethingToPrint = 1;
								antActions.append("#");
								antActions.append(to_string(ants[i]->getID()));
								antActions.append(" ");
								list->removeAnt(ants[i]->getID());
								removeAnt(ants[i]->getID());
							}
						}
					}
				}
				if (somethingToPrint) file << "    The AntHill was attacked and following ants died: " << antActions << "\n" << endl;
				if (!somethingToPrint) file << "    The AntHill was attacked and there were no ants defending." << "\n" << endl;
				food = 0;
				lost++;
			} else won++;
		}
	}
	while (food) {
		if (current_ants == 100)  {
			turn_num++;
			printFarmInfo();
			file << "    The AntHill has reached 100 ants." << endl;
		}
		list->insertAnt(new Ant(next_id));
		addAnt();
		food--;
	}
	if (current_ants == 100) {
		file << "    The AntHill has reached 0 ants." << endl;
	}
	antActions = "";
	turn_num++;
	// ofile << current_ants << endl;
}
