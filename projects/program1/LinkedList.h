#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include "Ant.h"

using namespace std;

class Node {
	public:
		Node(Ant * ant);
		~Node();
		Node * current;
		Node * next;
		Ant * ant;
		int singleDelete;
};

class LinkedList {
	private:
		Node * head;
	public:
		LinkedList();
		LinkedList(LinkedList * obj);
		~LinkedList();
		Ant * getAnt(int id);
		void removeAnt(int id);
		void insertAnt(Ant * ant);
		void operator<<(Ant * ant) {
			this->insertAnt(ant);
		}
};

#endif
