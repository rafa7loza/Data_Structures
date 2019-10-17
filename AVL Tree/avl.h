#ifndef AVL_H
#define AVL_H
#include <iostream>
#include "node.h"


class AVLTree{


public:
	AVLTree();
	void insert( Alumno &value){
		insert(root, value);
	}
	bool erase(const int &value){ return erase(root, value); }
	void preOrder(){ preOrder(root, 0); }
	void inOrder(){ inOrder(root); }
	void posOrder(){ posOrder(root); }


private:
	Node *root;
	bool erase(Node *&currentNode, const int &elem);
	void insert(Node *&currentNode,  Alumno &elem);
  void replaceNode(Node *&oldNode, Node *&currentNode);
	void preOrder(Node *currentNode, int level);
	void inOrder(Node *currentNode);
	void posOrder(Node *currentNode);
	void rebalanceInserted(Node *&node, Alumno &elem);
	void rebalanceDelete(Node *&);
	int getBalance(Node *currentNode);
	int updateHeight(Node *currentNode);
	int getHeight(Node *currentNode);
  Node* leftRotate(Node *&x);
  Node* rightRotate(Node *&y);
  // https://www.geeksforgeeks.org/avl-tree-set-1-insertion/
  // https://www.geeksforgeeks.org/avl-tree-set-2-deletion/
};

#endif
