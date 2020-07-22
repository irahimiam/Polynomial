#pragma once
#include "Node.h"

class List
{
public:
	Node * head;
public:
	List() { head = NULL; };
	~List();
	bool isEmpty() { return head == NULL; }
	Node * InsertNode(int, int , int);
	void DisplayList();
	List operator + (List &);
};

