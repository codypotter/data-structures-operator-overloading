/*
	Program:	CS-260 A1
	Author:		Cody Potter
	Date:		2018-04-06
	Purpose:	Unordered List class for a singly linked list in
				a generic template form
*/
#pragma once
#include<iostream>

using namespace std;

template <class dataType>
class UnOrderedList {
public:
	struct Node {
		dataType value;
		Node* next;
	};
	UnOrderedList();
	~UnOrderedList();
	void prepend(const dataType);
	void append(const dataType);
	bool remove(const dataType);
	void print();
	int count();
	int find(const dataType);
	void removeAll();
private:
	bool isInList(const dataType);
	Node* head;
};

template <class dataType>
UnOrderedList<dataType>::UnOrderedList() {
	head = NULL;
}

template <class dataType>
UnOrderedList<dataType>::~UnOrderedList() {
	this->removeAll();
}

template <class dataType>
void UnOrderedList<dataType>::prepend(const dataType userValue) {
	if (this->isInList(userValue)) { return; }
	Node* newNode = new Node;
	newNode->value = userValue;
	newNode->next = head;

	head = newNode;
}

template <class dataType>
void UnOrderedList<dataType>::append(const dataType userValue) {
	if (this->isInList(userValue)) { return; }
	Node* current = head;
	Node* newNode = new Node;
	newNode->value = userValue;
	newNode->next = NULL;

	if (!head) {
		head = newNode;
	} else {
		while (current->next) { current = current->next; }
		current->next = newNode;
	}

}

template <class dataType>
bool UnOrderedList<dataType>::remove(const dataType valueToRemove) {
	Node* current = head;
	Node* previous = NULL;

	while (current) {
		if (current->value == valueToRemove && !previous) {			// first case
			head = head->next;
			delete current;
			current = NULL;
			return true;
		} else if (current->value == valueToRemove && previous) {	// middle and last case
			previous->next = current->next;
			delete current;
			current = NULL;
			return true;
		}
		previous = current;
		current = current->next;
	}

	if (!current && !previous) { return false; }
	return false;
}

template <class dataType>
void UnOrderedList<dataType>::print() {
	cout << "The list contains the following " << this->count() << " elements: " << endl;
	Node* current = head;

	if (!current) { return; }

	while (current->next) {
		cout << current->value << ", ";
		current = current->next;
	}
	cout << current->value << endl;
	return;
}

template <class dataType>
int UnOrderedList<dataType>::count() {
	int count = 1;
	Node* current = head;
	if (!current) {
		return 0;
	}
	while (current) {
		count++;
		current = current->next;
	}
	return count;
}

template <class dataType>
int UnOrderedList<dataType>::find(const dataType checkValue) {
	Node* current = head;
	int positionTracker = 1;
	while (current->next) {
		current = current->next;
		positionTracker++;
		if (current->value == checkValue) {
			return positionTracker;
		}
	}
	return 0;
}

template <class dataType>
void UnOrderedList<dataType>::removeAll() {
	while (head) {
		Node* temp = head->next;
		delete head;
		head = temp;
	}
	head = NULL;
}

template <class dataType>
bool UnOrderedList<dataType>::isInList(const dataType checkValue) {
	Node* current = head;

	while (current) {
		if (current->value == checkValue) { return true; }
		current = current->next;
	}
	return false;
}


