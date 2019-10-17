#include "avl.h"
#include <iostream>

using namespace std;

AVLTree::AVLTree(){
	root = nullptr;
}

void AVLTree::insert(Node *&currentNode, Alumno &elem){
	if(currentNode == nullptr){
		currentNode = new Node(elem);
	}else if(elem.getId() < currentNode->value.getId()){
		if(!currentNode->left){
			Node *temp = new Node(elem);
			currentNode->left = temp;
		}else{
			insert(currentNode->left, elem);
		}
	}else if(elem.getId() > currentNode->value.getId()){
		if(!currentNode->right){
			Node *temp = new Node(elem);
			currentNode->right = temp;
		}else{
			insert(currentNode->right, elem);
		}
	}else if(currentNode->value.getId() == elem.getId()){
		return;
	}
	rebalanceInserted(currentNode, elem);
}


void AVLTree::replaceNode(Node *&oldNode, Node *&currentNode){
	if(currentNode->right != nullptr){
		replaceNode(oldNode, currentNode->right);
	}else{
		oldNode->value = currentNode->value;
		oldNode = currentNode;
		currentNode = currentNode->left;
	}
}


bool AVLTree::erase(Node *&currentNode, const int &elem){
	if(currentNode == nullptr){
		return false;
	}else if(elem < currentNode->value.getId()){
		return erase(currentNode->left, elem);
	}else if(elem > currentNode->value.getId()){
		return erase(currentNode->right, elem);
	}else{
		Node *oldRoot = currentNode;
		if(currentNode->left == nullptr){
			currentNode = currentNode->right;
		}else if(currentNode->right == nullptr){
			currentNode = currentNode->left;
		}else{
			replaceNode(oldRoot, currentNode->left);
		}

		delete oldRoot;
		if(currentNode != nullptr){
			rebalanceDelete(currentNode);
		}
		return true;
	}
}



void AVLTree::preOrder(Node *currentNode, int level){
        if (!currentNode){
        	return;
        }
				++level;
        cout << currentNode->value.getString() << endl;
        preOrder(currentNode->left, level);
        preOrder(currentNode->right, level);
}

void AVLTree::inOrder(Node *currentNode){
        if (!currentNode){
        	return;
        }
        inOrder(currentNode->left);
        cout << currentNode->value.getString() << endl;
        inOrder(currentNode->right);
}

void AVLTree::posOrder(Node *currentNode){
        if (!currentNode){
        	return;
        }
        posOrder(currentNode->left);
        posOrder(currentNode->right);
        cout << currentNode->value.getString() << endl;
}

int AVLTree::getBalance(Node *currentNode){
  if(currentNode == nullptr){
    return 0;
  }
  return getHeight(currentNode->left) - getHeight(currentNode->right);
}

int AVLTree::getHeight(Node *currentNode){
  if(currentNode == nullptr){
    return 0;
  }
  return currentNode->height;
}

int AVLTree::updateHeight(Node *currentNode){
	return max(getHeight(currentNode->left), getHeight(currentNode->right))+1;
}

Node* AVLTree::rightRotate(Node *&node){
	Node* x = node->left;
	Node* t2 = x->right;

	x->right = node;
	node->left = t2;

	x->height = updateHeight(x);
	node->height = updateHeight(node);

	return x;
}

Node* AVLTree::leftRotate(Node *&node){
	Node* y = node->right;
	Node* t2 = y->left;

	y->left = node;
	node->right = t2;

	node->height = updateHeight(node);
	y->height = updateHeight(y);

	return y;
}

void AVLTree::rebalanceInserted(Node *&node, Alumno &elem){
	node->height = updateHeight(node);

	int balance = getBalance(node);

	if(balance > 1 && elem.getId() < node->left->value.getId()){
		node = rightRotate(node);
	}else if(balance < -1 && elem.getId() > node->right->value.getId()){
		node = leftRotate(node);
	}else if(balance > 1 && elem.getId() > node->left->value.getId()){
		node->left = leftRotate(node->left);
		node = rightRotate(node);
	}else if(balance < -1 && elem.getId() < node->right->value.getId()){
		node->right = rightRotate(node->right);
		node = leftRotate(node);
	}
}

void AVLTree::rebalanceDelete(Node *&node){
	Node* rightChild = node->right;
	Node* leftChild = node->left;

	node->height = updateHeight(node);
	int balance = getBalance(node);

	if(balance > 1 && getBalance(leftChild) >= 0){
		node = rightRotate(node);
	}
	if(balance > 1 && getBalance(leftChild) < 0){
			node->left = leftRotate(node->left);
			node = rightRotate(node);
	}
	if(balance < -1 && getBalance(rightChild) <= 0){
		node = leftRotate(node);
	}
	if(balance < -1 && getBalance(rightChild) > 0){
			node->right = rightRotate(node->right);
			node = leftRotate(node);
	}
}
