#ifndef SORTER_H
#define SORTER_H

#include <vector>
#include <list>
#include <iostream>
#include <stdlib.h>
#include <ctime>

using namespace std;

// Class declaration for the template Sorter
template <class T>
class Sorter {
	private:
		T data;
		typename T::iterator iter;
	public:
		Sorter();
		void clear();
		unsigned int size();
		void insert(int i);
		bool emptyArray(int array[], int);
		void shuffle();
		typename T::iterator operator[] (int i);
		typename T::iterator get(int);
		void insertionSort();
		void selectionSort();
		void bubbleSort();
};

// Default constructor for Sorter.
template <class T>
Sorter<T>::Sorter() {
	iter = data.begin();
}

// empties either the List or Vector of all elements.
template <class T>
void Sorter<T>::clear() {
	data.clear();
}

// returns the size of the List or Vector
template <class T>
unsigned int Sorter<T>::size() {
	return data.size();
}

// Pushes the integer to the end of the List or Vector
template <class T>
void Sorter<T>::insert(int i) {
	data.push_back(i);
}

// Helper function for shuffle(), just checks the temporary array made in shuffle().
template <class T>
bool Sorter<T>::emptyArray(int array[], int theSize) {
	bool done = true;
	for (int i = 0; i < theSize; i++) {
		if (array[i] == 0) done = false;
	}
	return done;
}

// shuffles the elements inside of data.
template <class T>
void Sorter<T>::shuffle() {
	unsigned int arrSize = size();
	int list[arrSize];
	for (int i = 0; i < arrSize; i++) {
		int temp = data.back();
		data.pop_back();
		list[i] = temp;
	}
	int called[arrSize];
	for (int i = 0; i < arrSize; i++) called[i] = 0;
	while (!emptyArray(called, arrSize)) {
		bool found = false;
		int random = rand() % arrSize + 1;
		for (int i = 0; i < arrSize; i++) {
			if (called[random - 1] == 1) found = true;
		}
		if (!found) {
			data.push_back(list[random - 1]);
			called[random-1] = 1;
		}
	}
}

// Overloaded operator for Sorter, returns the iterator at an index.
template <class T>
typename T::iterator Sorter<T>::operator [] (int i) {
	typename T::iterator temp = data.begin();
	for (int j = 0; j < i; j++) {
		if (temp == data.end()) return temp;
		temp++;
	}
	return temp;
}

// helper function for the sorts, returns an iterator at an index.
template <class T>
typename T::iterator Sorter<T>::get (int i) {
	typename T::iterator temp = data.begin();
	for (int j = 0; j < i; j++) {
		if (temp == data.end()) return temp;
		temp++;
	}
	return temp;
}

// an insertion sort on to "data."
template <class T>
void Sorter<T>::insertionSort() {
	clock_t start;
	start = clock();
	cout << "\ninsertionSort attempt using " << size() << " entries of data. ";

	for (unsigned int i = 1; i < size(); i++) {
		int j = i;
		int maxValue = *(get(i));
		data.erase(get(i));
		while (j > 0 && *(get(j - 1)) > maxValue) {
			j--;
		}
		data.insert(get(j), maxValue);
	}
	cout << "Time took: " << (clock() - start) / (double)(CLOCKS_PER_SEC / 1000) << " ms" << endl;
}

// a selection sort on to "data."
template <class T>
void Sorter<T>::selectionSort() {
	clock_t start;
	start = clock();
	cout << "\nselectionSort attempt using " << size() << " entries of data. ";

	for (unsigned int i = 0; i < size() - 1; i++) {
		typename T::iterator min = get(i);
		for (unsigned int j = i + 1; j < size(); j++) {
			typename T::iterator element = get(j);
			if (*element < *min) {
				int temp = *min;
				*min = *element;
				*element = temp;
			}
		}
	}
	cout << "Time took: " << (clock() - start) / (double)(CLOCKS_PER_SEC / 1000) << " ms" << endl;
}

// a bubble sort on to "data."
template <class T>
void Sorter<T>::bubbleSort() {
	clock_t start;
	start = clock();
	cout << "\nbubbleSort attempt using " << size() << " entries of data. ";

	bool finished = false;
	while(!finished){
		finished = true;
		for (unsigned int i = 0; i < size() - 1 ; i++) {
			typename T::iterator leftElement = (get(i));
			typename T::iterator rightElement = (get(i + 1));
			if (*leftElement > *rightElement) {
				*leftElement += *rightElement;
				*rightElement = *leftElement - *rightElement;
				*leftElement -= *rightElement;
				finished = false;
			}
		}
	}
	cout << "Time took: " << (clock() - start) / (double)(CLOCKS_PER_SEC / 1000) << " ms" << endl;
}

#endif
