#ifndef MAP_H
#define MAP_H

#include "City.h"
#include <vector>

class Map {
	private:
		std::vector<City*> cities;
	public:
		Map (std::string filename);
		~Map();
		City* findByName(std::string cityName);
		std::vector<City*> shortestPath (City * start, City * dest);
		unsigned int pathDistance (City * start, City * dest);
		void addAdjacencies(City* city);
		void setDistances(City* current);
		void clear();
};

#endif
