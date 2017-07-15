#ifndef BSTREE_H
#define BSTREE_H

#include <vector>

class BSTree {
	private:
		class Node {
			public:
				Node(int data);
				~Node();
				Node * parent;
				Node * left;
				Node * right;
				int data;
				int shiftRight;
				int shiftLeft;
		};
		Node * root;
	public:
		BSTree();
		BSTree(const BSTree &old_tree);
		~BSTree();
		void startPrintTree();
		void printTree(Node *, int);
		void deleteAll(Node *);
		bool empty();
		bool insert(int);
		bool find(int);
		void sortedArray(std::vector<int> &list);
		bool remove(int);
		void traverseAdd(Node *);
//		void newTraverseVector(Node *, std::vector<int> &list);
		void traverseVector(Node *, std::vector<int> &list);
};

#endif
