#include <iostream>
#include <string>

#include "City.h"

using namespace std;

// City constructor. Assigns default values to distance, previous & visited. Assigns city name, x, & y.
City::City(string cityName, int xCoord, int yCoord) {
	name = cityName;
	x = xCoord;
	y = yCoord;
	distance = -1;
	previous = NULL;
	visited = 0;
}

// Overloaded operator for comparing cities.
bool City::operator < (City &c) {
	return distance < c.distance;
}

// Returns the list of adjacent cities.
list<City*> City::getAdjacent() {
	return adjacencies;
}

// Adds a city to the adjacency list.
void City::addAdj(City* city) {
	adjacencies.push_back(city);
}
