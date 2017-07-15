#ifndef PLAYER_H
#define PLAYER_H

#include "Card.h"
#include <string>

class Player {
	private:
		std::string name;
		int budget;
	public:
		Card hand;

		Player();
		Player (std::string, int);
		std::string getName();
		int getBudget();
		bool bet(int);
		void collectWinnings(int);
};

#endif
