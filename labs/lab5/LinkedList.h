#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include <iostream>

using namespace std;

// template class for Node which takes <T> data.
template <class T>
class Node {
	friend class Deck;
	friend class lab5;
	public:
		Node(T data);
//		~Node();
		Node * next;
		T data;
		int singleDelete;
};

// template class for LinkedList that takes <T> data and is friends with Queue class.
template <class T>
class LinkedList {
	template <class T2> friend class Queue;
	friend class Deck;
	friend class lab5;
	private:
		Node<T> * head;
		Node<T> * current;
	public:
		LinkedList();
		~LinkedList();
		LinkedList(LinkedList<T> * obj);
		void insert(T data);
		T read();
		bool empty();
		bool remove(T data);
		void operator << (T data) {
			this->insert(data);
		}
		void operator == (T data) {
			this->remove(data);
		}
};


// constructor for Node based on a data of type <T>
template <class T>
Node<T>::Node(T newData) {
	data = newData;
	next = NULL;
	singleDelete = 0;
}

// destructor for Node, changes how it destructs depending on if it's a single delete
// or a mass delete of a LinkedList.
/*
template <class T>
Node<T>::~Node() {
	if (singleDelete) {
		// delete data;
	}
	else {
		// delete data;
		if (next != NULL) {}//delete next;
	}
}
*/

// LinkedList constructor that just sets head to NULL
template <class T>
LinkedList<T>::LinkedList() {
	head = NULL;
	current = head;
}

// copy constructor for LL, which is a deep copy
template <class T>
LinkedList<T>::LinkedList(LinkedList<T> * otherList) {
	if (otherList == NULL) {
		head = NULL;
		return;
	}
	Node<T> * temp = otherList->head;
	head = new Node<T>(temp->data);
	Node<T> * headTemp = head;
	temp = temp->next;
	while (temp != NULL) {
		head->next = new Node<T>(temp->data);
		temp = temp->next;
		head = head->next;
	}
	head = headTemp;
}

// destructor for LL, all the interesting parts are in the destructor for Node

template <class T>
LinkedList<T>::~LinkedList() {
	delete head;
}


// inserts an data into the LL
template <class T>
void LinkedList<T>::insert(T data) {
	if (head == NULL) {
		head = new Node<T>(data);
		return;
	}
	Node<T> * temp;
	for (temp = head; temp->next != NULL; temp = temp->next) {}
	temp->next = new Node<T>(data);
	return;
}

// returns an data of type <T> from the current Node pointer.
template <class T>
T LinkedList<T>::read() {
	if (current == NULL) current = head;
	T tempData = current->data;
	if (current->next == NULL) current = head;
	else current = current->next;
	return tempData;
}

// checks to see if the LL is empty based on head's value.
template <class T>
bool LinkedList<T>::empty() {
	if (head == NULL) return true;
	return false;
}

// removes an Node from the LL based on the data (true if successful).
template <class T>
bool LinkedList<T>::remove(T checkData) {
	Node<T> * temp = head;
	if (head->data == checkData) {
		head = head->next;
		temp->singleDelete = 1;
		delete temp;
		return true;
	}
	while(temp->next != NULL) {
		if (temp->next->data == checkData) {
			Node<T> * shiftTemp = temp->next;
			temp->next = temp->next->next;
			shiftTemp->singleDelete = 1;
			delete shiftTemp;
			return true;
		}
		temp = temp->next;
	}
	return false;
}

#endif
