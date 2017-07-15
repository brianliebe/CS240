#include "BSTree.h"
#include <iostream>
#include <iomanip>
#include <vector>
#include <string>

using namespace std;

// default constructor for Node. sets all pointers to NULL and the data to newData.
BSTree::Node::Node(int newData) {
	data = newData;
	left = NULL;
	right = NULL;
	parent = NULL;
	shiftRight = 0;
	shiftLeft = 0;
}

// Destructor for Node, but it's not used here.
BSTree::Node::~Node() {
	//
}

// Default constructor for BSTree, just sets root to NULL
BSTree::BSTree() {
	root = NULL;
}

// Destructor for BSTree, it just calls deleteAll(root)
BSTree::~BSTree() {
	deleteAll(root);
}

// Starts the printing of the tree
void BSTree::startPrintTree() {
	int id = 0;
	printTree(root, id);
}

// prints out the BST
void BSTree::printTree(Node * n, int id)
{
	int shifter = 4;
	if (n) {
		vector<int> rightList;
		vector<int> leftList;
		if (n->right && n->right->left) {
			traverseVector(n->right->left, rightList);
		}
		if (n->left && n->left->right) {
			traverseVector(n->left->right, leftList);
		}
		n->shiftRight += rightList.size();
		n->shiftLeft += leftList.size();
		if (n->right) {
			printTree(n->right, id + shifter);
			if (n->shiftRight < n->shiftLeft) {
				int temp = n->shiftLeft - n->shiftRight;
				if (n->parent && n->parent->right == n) n->parent->shiftRight+=temp;
				if (n->parent && n->parent->left == n) n->parent->shiftLeft+=temp;
				temp = temp * 2;
				while (temp > 0) {
					cout << endl;
					temp--;
				}
			}
		}
		if (id) {
			cout << setw(id) << ' ';
		}
		if (n->right) {
			if (n != root) {
				cout << " /\n" << setw(id) << ' ';
			}
			else {
				cout << "  /\n" << setw(id) << ' ';
			}
		}

		if (n->data < 10) cout << "0" << n->data;
		else cout << n->data;
		int lengthVal = 45 - id;
		if (n == root) lengthVal--;
		cout << ' ';
		while (lengthVal) {
			cout << "-";
			lengthVal --;
		}
		cout << endl;

		if(n->left) {
			cout << setw(id) << ' ' << " \\\n";;
			if (n->shiftLeft < n->shiftRight) {
				int temp = n->shiftRight - n->shiftLeft;
				if (n->parent && n->parent->right == n) n->parent->shiftRight+=temp;
				if (n->parent && n->parent->left == n) n->parent->shiftLeft+=temp;
				temp = temp * 2;
				while (temp > 0) {
					cout << endl;
					temp--;
				}
			}
			printTree(n->left, id + shifter);
		}
	}
}

// Used to delete all nodes
void BSTree::deleteAll(Node * n) {
	if (n != NULL) {
		deleteAll(n->left);
		deleteAll(n->right);
		delete n;
	}
}

// Helper function along side the copy constructor, it uses pre-order traversing
void BSTree::traverseAdd(Node * n) {
	Node * temp = n;
	if (n != NULL) {
		int tempData = temp->data;
		insert(tempData);
		if (temp->left != NULL) traverseAdd(temp->left);
		if (temp->right != NULL) traverseAdd(temp->right);
	}
}

// Calls traverseAdd to deep copy from old_tree.
BSTree::BSTree(const BSTree &old_tree) { // pre-order
	if (old_tree.root == NULL) return;
	else {
		root = new BSTree::Node(old_tree.root->data);
		traverseAdd(old_tree.root);
	}
}

// checks to see if the BST is empty
bool BSTree::empty() {
	if (root == NULL) return true;
	else return false;
}

// inserts a new value into the BST
bool BSTree::insert(int val) {
	Node * temp = root;
	if (temp == NULL) {
		root = new BSTree::Node(val);
		return true;
	}
	while (true) {
		if (val > temp->data) {
			if (temp->right == NULL) {
				temp->right = new BSTree::Node(val);
				temp->right->parent = temp;
				return true;
			} else temp = temp->right;
		}
		if (val < temp->data) {
			if (temp->left == NULL) {
				temp->left = new BSTree::Node(val);
				temp->left->parent = temp;
				return true;
			} else temp = temp->left;
		}
		if (val == temp->data) return false;
	}
}

// returns true if the "val" is found within the BST
bool BSTree::find(int val) {
	Node * temp = root;
	if (temp == NULL) return false;
	while (true) {
		if (val > temp->data) {
			if (temp->right == NULL) return false;
			else temp = temp->right;
		}
		if (val < temp->data) {
			if (temp->left == NULL) return false;
			else temp = temp->left;
		}
		if (val == temp->data) return true;
	}
}

// Helper function for sortedArray, it used in-order traversing within the BST
void BSTree::traverseVector(Node * n, vector<int> &list) {
	Node * temp = n;
	if (temp != NULL) {
		if (temp->left != NULL) traverseVector(temp->left, list);
		list.push_back(temp->data);
		if (temp->right != NULL) traverseVector(temp->right, list);
	}
}

// adds all values in the BST, sorted, into list
void BSTree::sortedArray(vector<int> &list) {
	if (root == NULL) {
		return;
	}
	else {
		if (root->data == 0) traverseVector(root->right, list);
		else {
			traverseVector(root, list);
		}
	}
}

// removes a value from the BST
bool BSTree::remove(int num) {
	if (root == NULL) return false;
	Node * foundNode;
	Node * temp = root;
	Node * replacement;
	bool done = false;
	while (!done) {
		if (num > temp->data) {
			if (temp->right == NULL) return false;
			else temp = temp->right;
		}
		if (num < temp->data) {
			if (temp->left == NULL) return false;
			else temp = temp->left;
		}
		if (num == temp->data) {
			done = true;
			foundNode = temp;
		}
	}
	temp = foundNode;
	if (temp->right == NULL) {
		if (temp->left == NULL) {
			if (temp->parent != NULL) {
				if (temp->parent->right != NULL) {
					if (temp->parent->right->data == temp->data) temp->parent->right = NULL;
				}
				if (temp->parent->left != NULL) {
					if (temp->parent->left->data == temp->data) temp->parent->left = NULL;
				}
			} else {
				root = NULL;
			}
			delete temp;
			return true;
		} else {
			if (temp->parent->right != NULL) {
				if (temp->parent->right->data == temp->data) {
					temp->parent->right = temp->left;
					temp->left->parent = temp->parent;
				}
			}
			if (temp->parent->left != NULL) {
				if (temp->parent->left->data == temp->data) {
					temp->parent->left = temp->left;
					temp->left->parent = temp->parent;
				}
			}
			delete temp;
			return true;
		}
	} else {
		temp = temp->right;
		if (temp->left == NULL) {
			foundNode->data = temp->data;
			foundNode->right = temp->right;
			if (temp->right != NULL) temp->right->parent = temp->parent;
			delete temp;
			return true;
		} else {
		while (temp->left != NULL) temp = temp->left;
		replacement = temp;
		foundNode->data = replacement->data;
		replacement->parent->left = replacement->right;
		if (replacement->right != NULL) replacement->right->parent = replacement->parent;
		delete replacement;
		return true;
		}
	}
}
