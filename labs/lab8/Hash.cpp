#include <iostream>
#include <string>
#include <vector>
#include "Hash.h"

using namespace std;

Hash::Hash (unsigned int newSize) {
	arrSize = newSize;
	for (unsigned int i = 0; i < newSize; i++) array.push_back(make_pair("",""));
}

bool Hash::insert (string key, string value) {
	for (unsigned int i = hasher(key), j = 0; j < arrSize; i++, j++) {
		if (array[i].first == "") {
			array[i] = make_pair (key, value);
			break;
		}
		if (i+1 >= arrSize) i = 0;
	}
	return true;
}

bool Hash::remove (string key) {
	for (unsigned int i = hasher(key), j = 0; j < arrSize; i++, j++) {
		if (array[i].first == key) {
			array[i] = make_pair("","");
			return true;
		}
		if (i+1 >= arrSize) i = 0;
	}
	return false;
}

string Hash::find (string key) {
	for (unsigned int i = hasher(key), j = 0; j < arrSize; i++, j++) {
		if (array[i].first == key) return array[i].second;
		if (i+1 >= arrSize) i = 0;
	}
	return "";
}

bool Hash::empty() {
	for (unsigned int i = 0; i < arrSize; i++) {
		if (array[i].first != "") return false;
	}
	return true;
}

int Hash::size() {
	return arrSize;
}

void Hash::printHash() {
	for (unsigned int i = 0; i < arrSize; i++) {
		cout << "Index:" << i;
		cout << "\t\t\t\tKey: " << array[i].first;
		if (array[i].first == "") cout << "\t";
		cout << "\t\t\tValue: " << array[i].second << endl;
	}
}

int Hash::hasher (string key) {
	return key.length() % arrSize;
}
