#include <iostream>
#include <algorithm>
#include <fstream>
#include <string>
#include <vector>
#include "City.h"
#include "Map.h"

using namespace std;

// Contructor for Map. Reads a filename and adds cities into the 'cities' vector using string manipulation
Map::Map (string filename) {
	string line;
	ifstream file (filename);
	if (file.is_open()) {
		while (getline(file, line)) {
			// Finds the first " ", then cuts it, then finds the next " " etc. This way
			// it will find the name and x,y.
			string name = line.substr(0, line.find(" "));
			line.replace(0, line.find(" ") + 1, "");
			string x = line.substr(0, line.find(" "));
			line.replace(0, line.find(" ") + 1, "");
			string y = line.substr(0, line.find(" "));
			City * temp = new City(name, stoi(x), stoi(y));
			cities.push_back(temp);
		}
		file.close();
	}
	// This sets the adjacencies for each city individually.
	for (unsigned int i = 0; i < cities.size(); i++) {
		City * temp = cities[i];
		addAdjacencies(temp);
	}
}

// Destructor for Map, removes the cities.
Map::~Map() {
	for (auto iter: cities) delete iter;
}

// Takes in a city name as a string, and loops through the cities until one is found.
City* Map::findByName (string cityName) {
	if (cityName == "") return NULL;
	for (unsigned int i = 0; i < cities.size(); i++) {
		if (cities[i]->getName() == cityName) return cities[i];
	} return NULL;
}
// Returns the shortest path between two cities. It calls "setDistances" which really does all the work.
vector<City*> Map::shortestPath(City * start, City * dest) {
	vector<City*> retVector;
	clear();
	start->setDist(0);
	setDistances(start);
	if (dest->getDist() == -1) return retVector; // this means there is no connection
	City * temp = dest;
	// This will create a list of all of the cities (backwards) needed to get to the start.
	while (temp != NULL) {
		retVector.push_back(temp);
		temp = temp->getPrevious();
	}
	vector<City*> final;
	// This reverses the order of the vector's elements, so that it's A->B not B->A.
	for (int i = retVector.size() - 1; i >= 0; i--) final.push_back(retVector[i]);
	return final;
}

// Helper function that just resets all the cities distances, visited values, and previous cities.
void Map::clear() {
	for (auto r: cities) {
		r->setDist(-1);
		r->setVisited(0);
		r->setPrevious(NULL);
	}
}

// The "meat" of my program. This will assign a "distance" value to every city.
// It will be called on each city once.
void Map::setDistances (City * current) {
	list<City*> adjacenciesList = current->getAdjacent();
	vector<City*> adj;
	int tempSize = adjacenciesList.size();

	// changes the list into a vector, just because it was easier for me to work with.
	for (int i = 0; i < tempSize; i++) {
		adj.push_back(adjacenciesList.front());
		adjacenciesList.pop_front();
	}

	// This will call on every city adjacent to the current city.
	for (unsigned int i = 0; i < adj.size(); i++) {
		// Get variables for every coordinate (easier).
		int currX = current->getXCoor();
		int currY = current->getYCoor();
		int adjX = adj[i]->getXCoor();
		int adjY = adj[i]->getYCoor();

		// If they're on the same X axis:
		if (adjX == currX) {
			int diff;
			if (adjY > currY) diff = adjY - currY;
			else diff = currY - adjY;
			// if the value doesn't have a distance, assign one.
			if (adj[i]->getDist() == -1) {
				adj[i]->setDist(current->getDist() + diff);
				adj[i]->setPrevious(current);
			}
			// if it does have one, change it if it's bigger than the current route.
			else {
				if (adj[i]->getDist() > current->getDist() + diff) {
					adj[i]->setDist(current->getDist() + diff);
					adj[i]->setPrevious(current);
				}
			}
		}

		// If they're on the same Y axis:
		if (adjY == currY) {
			int diff;
			if (adjX > currX) diff = adjX - currX;
			else diff = currX - adjX;
			// if the value doesn't have a distance, assign one.
			if (adj[i]->getDist() == -1) {
				adj[i]->setDist(current->getDist() + diff);
				adj[i]->setPrevious(current);
			}
			// if it does have one, change it if it's bigger than the current route.
			else {
				if (adj[i]->getDist() > current->getDist() + diff) {
					adj[i]->setDist(current->getDist() + diff);
					adj[i]->setPrevious(current);
				}
			}
		}
	}
	current->setVisited(1);

	// This sorts the vector so that the closer cities are called first.
	sort(adj.begin(), adj.end(), [](City* city1, City* city2){
		return city1->getDist() < city2->getDist();
	});
	// Recursively call on all possible cities via their adjacents.
	for (unsigned int i = 0; i < adj.size(); i++) {
		if (adj[i]->getVisited() == 0) setDistances(adj[i]);
	}
}

// Returns the "distance" variable of a city after setDistances is called.
unsigned int Map::pathDistance (City * start, City * dest) {
	clear();
	start->setDist(0);
	setDistances(start);
	return dest->getDist();
}

// Sets the adjacencies for each city.
void Map::addAdjacencies(City * city) {
	// Easy-to-use variables for x,y coords.
	int x = city->getXCoor();
	int y = city->getYCoor();
	// The possible cities that could be adjacent to "city"
	City * temp;
	City * north = NULL;
	City * east = NULL;
	City * south = NULL;
	City * west = NULL;
	// Runs for every city in "cities"
	for (unsigned int i = 0; i < cities.size(); i++) {
		temp = cities[i];
		// Checks if they're on the same X-axis & assigns them if they're close.
		if (temp->getXCoor() == x) {
			// For the north city
			if (temp->getYCoor() > y) {
				if (north == NULL) north = temp;
				else {
					if (north->getYCoor() > temp->getYCoor()) north = temp;
				}
			}
			// For the south city
			if (temp->getYCoor() < y) {
				if (south == NULL) south = temp;
				else {
					if (south->getYCoor() < temp->getYCoor()) south = temp;
				}
			}
		}
		// Checks if they're on the same Y-axis & assigns them if they're close.
		if (temp->getYCoor() == y) {
			// For the east city
			if (temp->getXCoor() > x) {
				if (east == NULL) east = temp;
				else {
					if (east->getXCoor() > temp->getXCoor()) east = temp;
				}
			}
			// For the west city
			if (temp->getXCoor() < x) {
				if (west == NULL) west = temp;
				else {
					if (west->getXCoor() < temp->getXCoor()) west = temp;
				}
			}
		}
	}
	// Adds them to adjacencies if they exist
	if (north != NULL) city->addAdj(north);
	if (east != NULL) city->addAdj(east);
	if (south != NULL) city->addAdj(south);
	if (west != NULL) city->addAdj(west);
}
