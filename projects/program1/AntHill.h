#ifndef ANTHILL_H
#define ANTHILL_H

#include "Ant.h"
#include "LinkedList.h"
#include <fstream>
#include <string>

class AntHill {
	private:
		ofstream file;
		Ant ** ants;
		LinkedList * list;
		int attacked, won, lost, turn_num, max_ants;
		int food, current_ants, next_id, maxX, maxY;
		string antActions;
	public:
		AntHill();
		~AntHill();
		int addAnt();
		bool removeAnt(int);
		Ant * getAnt(int);
		void move();
		void printHillInfo();
		void printFarmInfo();
		inline int getCurrentNumAnts() { return current_ants; }
		void turn();
};



#endif
