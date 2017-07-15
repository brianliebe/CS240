#include "AntHill.h"
#include "Ant.h"
#include "LinkedList.h"
#include <iostream>

// constructor for Node based on an Ant (newAnt)
Node::Node(Ant * newAnt) {
	ant = newAnt;
	next = NULL;
	singleDelete = 0;
}

// destructor for Node, changes how it destructs depending on if it's a single delete or a mass delete of a LinkedList.
Node::~Node() {
	if (singleDelete) delete ant;
	else {
		delete ant;
		if (next != NULL) delete next;
	}
}

// LinkedList constructor that just sents head to NULL
LinkedList::LinkedList() {
	head = NULL;
}

// copy constructor for LL, which is a deep copy
LinkedList::LinkedList(LinkedList * otherList) {
	if (otherList == NULL) {
		head = NULL;
		return;
	}
	Node * temp = otherList->head;
	head = new Node(temp->ant);
	Node * headTemp = head;
	temp = temp->next;
	while (temp != NULL) {
		head->next = new Node(temp->ant);
		temp = temp->next;
		head = head->next;
	}
	head = headTemp;
}

// destructor for LL, all the interesting parts are in the destructor for Node
LinkedList::~LinkedList() {
	delete head;
}

// inserts an ant into the LL
void LinkedList::insertAnt(Ant * ant) {
	if (head == NULL) {
		head = new Node(ant);
		return;
	}
	Node * temp;
	for (temp = head; temp->next != NULL; temp = temp->next) {}
	temp->next = new Node(ant);
	return;
}

// returns an Ant pointer based on the ant's ID
Ant * LinkedList::getAnt(int antID) {
	Node * temp;
	for (temp = head; temp->ant->getID() != antID; temp = temp->next) {}
	return temp->ant;
}

// removes an ant from the LL based on the ant's ID
void LinkedList::removeAnt(int antID) {
	Node * temp = head;
	while(temp->next != NULL) {
		if (temp->next->ant->getID() == antID) {
			Node * temp2 = temp->next;
			temp->next = temp->next->next;
			temp2->singleDelete = 1;
			delete temp2;
			return;
		}
		temp = temp->next;
	}
}
