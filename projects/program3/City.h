#ifndef CITY_H
#define CITY_H

#include <list>

class City {
	private:
		int x, y, distance, visited;
		std::string name;
		City * previous;
		std::list<City*> adjacencies;
	public:
		City(std::string cityName, int xCoor, int yCoor);
		inline std::string getName() { return name; }
		inline int getXCoor() { return x; }
		inline int getYCoor() { return y; }
		inline int getDist() { return distance; }
		inline int getVisited() { return visited; }
		std::list<City*> getAdjacent();
		bool operator < (City &c);
		void addAdj(City* city);
		inline void setDist(int dist) { distance = dist; }
		inline void setVisited(int value) { visited = value; }
		inline City* getPrevious() { return previous; }
		inline void setPrevious(City* city) { previous = city; }
};

#endif
