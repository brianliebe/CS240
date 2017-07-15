#ifndef HEAP_H
#define HEAP_H

#include "Player.h"

#include <vector>
#include <string>

class Heap {
	private:
		std::vector<Player> players;
		bool isLeaf(int);
		void heapify();
		void siftDown(int);
		Player removePriority();
	public:
		Heap();
		Heap(std::string filename);
		Heap(Heap &copy);
		void addPlayer(Player newPlayer);
		Player getPlayer();
		std::vector<Player> getArray();
		bool empty();
		unsigned int size();
};

#endif
