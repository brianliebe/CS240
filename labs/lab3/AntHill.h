#ifndef ANTHILL_H
#define ANTHILL_H

#include "Ant.h"

class AntHill {
	private:
		int max_ants;
		Ant ** ants;
		int current_ants;
		// Ant ants[100];
		int next_id;
	public:
		AntHill();
		~AntHill();
		int addAnt();
		bool removeAnt(int);
		Ant * getAnt(int);
		void move();
		void printHillInfo();
		inline int getCurrentNumAnts() { return current_ants; }
};



#endif
