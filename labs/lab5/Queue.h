#ifndef QUEUE_H
#define QUEUE_H

#include "LinkedList.h"
#include <stdlib.h>
#include <iostream>

// template for Queue based on LL.
template <class T>
class Queue {
	friend class LinkedList<T>;
	friend class Deck;
	friend class Card;
	private:
		bool queueDeleted;
		LinkedList<T> * queue;
	public:
		Queue();
		bool enqueue(T data);
		T dequeue();
		T peek();
		bool empty();
		void clear();
};

// default constructor for Queue, sets queue to NULL and sets my testing boolean.
template <class T>
Queue<T>::Queue() {
	queueDeleted = true;
	queue = NULL;
}

// enqueue will add <T> data to the beginning of the LL
template <class T>
bool Queue<T>::enqueue (T data){
	if (queue == NULL){
		queue = new LinkedList<T>();
		queue->head = NULL;
		queueDeleted = false;
	}
	if (queue->head == NULL) {
		queue->insert(data);
		queue->head->next = NULL;
	}else {
		Node<T> * temp = new Node<T>(data);
		temp->next = queue->head;
		queue->head = temp;
	}
	return true;
}

// dequeue will remove the Node from the last Node in the LL and return a copy of its data.
template <class T>
T Queue<T>::dequeue () {
	Node<T> * temp;
	for (temp = queue->head; temp->next != NULL; temp = temp->next) {}
	T tempData = temp->data;
	queue->remove(tempData);
	if (empty()) {
		delete queue;
		queue = NULL;
		queueDeleted = true;
	}
	return tempData;
}

// peek will just return a copy of the data within the last LL Node
template <class T>
T Queue<T>::peek() {
	Node<T> * temp;
	for (temp = queue->head; temp->next != NULL; temp = temp->next) {}
	T tempData = temp->data;
	return tempData;
}

// empty just checks to see if the queue is NULL or empty.
template <class T>
bool Queue<T>::empty() {
	if (queueDeleted || queue == NULL || queue->head == NULL) return true;
	return false;
}

// clear will just clear everything in queue. This works because of my destructor in Node (using singleDelete)
template <class T>
void Queue<T>::clear() {
	delete queue->head;
	queue->head = NULL;
	delete queue;
	queue = NULL;
	return;
}

#endif
