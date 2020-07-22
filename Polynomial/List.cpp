#include "stdafx.h"
#include "List.h"
#include <iostream>
#include <string>

using namespace std;


List::~List()
{
	Node * currNode = head;
	Node * nextNode = NULL;
	while (currNode) {
		nextNode = currNode->next;
		delete currNode;
		currNode = nextNode;
	}
}

Node * List::InsertNode(int con, int power , int index) {
	if (index < 0){
		return NULL;
	}
	int currindex = 1;
	Node * currNode = head;
	while (currNode && index>currindex) {
		currNode = currNode->next;
		currindex++;
	}
	if (index > 0 && currNode == NULL) {
		return NULL;
	}

	Node * NewNode = new Node;
	NewNode->coeff = con;
	NewNode->pow = power;

	if (index == 0) {
		NewNode->next = head;
		head = NewNode;
	}
	else {
		NewNode->next = currNode->next;
		currNode->next = NewNode;
	}
	return NewNode;
}

void List::DisplayList() {
	Node * currNode = head;
	while (currNode != NULL) {
		cout<< currNode->coeff << 'X' << currNode->pow << '+';
		currNode = currNode->next;
	}
	cout << "\b ";
}

List List::operator + (List &poly) {
	Node *temp_1 = head;
	Node *temp_2 = poly.head;
	List answer;

	int i = 0;
	while (temp_1 != NULL || temp_2 != NULL) {
		if (temp_1->pow > temp_2->pow) {
			answer.InsertNode(temp_1->coeff, temp_1->pow, i);
			temp_1 = temp_1->next;
			i++;
		}
		else if (temp_1->pow < temp_2->pow) {
			answer.InsertNode(temp_2->coeff, temp_2->pow, i);
			temp_2 = temp_2->next;
			i++;
		}
		else if (temp_1->pow == temp_2->pow) {
			answer.InsertNode(temp_1->coeff + temp_2->coeff, temp_1->pow, i);
			i++;
			temp_2 = temp_2->next;
			temp_1 = temp_1->next;
		}
	}
	if (temp_1 != NULL) {
		while (temp_1 != NULL) {
			answer.InsertNode(temp_1->coeff, temp_1->pow, i);
			temp_1 = temp_1->next;
			i++;
		}
	}
	else {
		while (temp_2 != NULL) {
			answer.InsertNode(temp_2->coeff, temp_2->pow, i);
			temp_2 = temp_2->next;
			i++;
		}
	}
	return answer;
}