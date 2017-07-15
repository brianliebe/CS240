#include "Heap.h"

#include <iostream>
#include <algorithm>
#include <vector>
#include <fstream>

using namespace std;

// default constructor for Heap
Heap::Heap() {
	players = {};
}

// reads a file name and creates players to add to the heap.
Heap::Heap(string filename) {
	string line;
	ifstream file (filename);
	if (file.is_open()) {
		// uses the next 2 lines to create a new player.
		while (getline(file, line)) {
			string tline = line;
			getline(file, line);
			Player temp(tline, stoi(line));
			addPlayer(temp);
		}
		file.close();
	}
}

// checks to see if a "node" has children. True if it doesn't, false if it does.
bool Heap::isLeaf(int i) {
	unsigned int id1 = i*2 + 1;
	unsigned int id2 = i*2 + 2;
	if (id1 >= players.size() && id2 >= players.size()) return true;
	return false;
}

// heapifies the array.
void Heap::heapify() {
	int n = players.size() - 1;
	for (int i = ((n - 1)/2); i >= 0; i--) {
		siftDown(i);
	}
}

// sifts down values to make sure the heap stays heapified.
void Heap::siftDown(int i) {
	if (i < 0 || i >= players.size()) return;
	while (!isLeaf(i)) {
		int child = 2*i + 1;
		if (child + 1 < players.size() && players[child].getBudget() < players[child + 1].getBudget()) child += 1;
		if (players[i].getBudget() < players[child].getBudget()) {
			swap(players[i], players[child]);
		}
		else return;
		i = child;
	}
}

// replaces the first and last values in the array, then removes the last one.
// this will remove the max value in the heap.
Player Heap::removePriority() {
	heapify();
	swap(players[0], players[players.size() - 1]);
	Player temp = players.back();
	players.pop_back();
	heapify();
	return temp;
}

// copy constructor based off a referenced Heap.
Heap::Heap(Heap &copy) {
	if (copy.empty()) return;
	for (unsigned int i = 0; i < copy.size(); i++) {
		players.push_back((copy.getArray())[i]);
	}
}

// adds a new player to the heap
void Heap::addPlayer(Player newPlayer) {
	players.push_back(newPlayer);
	heapify();
}

// heapifies, then calls removePriority to get a max player from the heap.
Player Heap::getPlayer() {
	heapify();
	return removePriority();
}

// returns the internal array for the heap.
vector<Player> Heap::getArray() {
	return players;
}

// checks to see if the heap is empty or not
bool Heap::empty() {
	if (players.size() == 0) return true;
	return false;
}

// returns the size of the heap
unsigned int Heap::size() {
	return players.size();
}
