#ifndef NODE_H
#define NODE_H
#include <iostream>
#include "alumno.h"

class Node{
public:
	// Node(int elem) : value(elem), left(nullptr), right(nullptr){}
	// int value;
	Node(Alumno alumno) : value(alumno), left(nullptr), right(nullptr), height(0){}
	Alumno value;
	Node *left, *right;
	int height;
};

#endif // NODE_H
