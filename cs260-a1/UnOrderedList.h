#pragma once
#include<iostream>

using namespace std;

class UnOrderedList {
public:
	struct Node {
		int value;
		Node* next;
	};
	UnOrderedList();
	~UnOrderedList();
	void prepend(const int);
	void append(const int);
	bool remove(const int);
	void print();
	int count();
	int find(const int);
	void removeAll();
private:
	bool isInList(const int);
	Node* head;
};

UnOrderedList::UnOrderedList() {
	head = NULL;
}

UnOrderedList::~UnOrderedList() {
	this->removeAll();
}

void UnOrderedList::prepend(const int userValue) {
	if (this->isInList(userValue)) {
		return;
	}
	Node* newNode = new Node;
	newNode->value = userValue;
	newNode->next = head;

	head = newNode;
}

void UnOrderedList::append(const int userValue) {
	if (this->isInList(userValue)) {
		return;
	}
	Node* newNode = new Node;
	newNode->value = userValue;
	newNode->next = NULL;

	if (!head) {
		head = newNode;
		return;
	} else {
		Node* last = head;
		while (last->next) {
			last = last->next;
		}
		last->next = newNode;
	}
}

bool UnOrderedList::remove(const int numToRemove) {
	Node* current = head;
	Node* previous = current;
	while (current) {
		if (current->value == numToRemove) {
			previous->next = current->next;
			delete current;
			return true;
		}
		previous = current;
		current = current->next;
	}
	return false;;
}

void UnOrderedList::print() {
	cout << "The list contains the following " << this->count() << " elements: " << endl;
	Node* current = head;

	while (current->next) {
		cout << current->value << ", ";
		current = current->next;
	}
	cout << current->value;
	cout << endl;
}

int UnOrderedList::count() {
	int count = 0;
	if (head) {
		Node* current = head;
		count = 1;
		while (current->next) {
			current = current->next;
			count++;
		}
	}
	return count;
}

int UnOrderedList::find(const int checkNumber) {
	Node* current = head;
	int positionTracker = 1;
	while (current->next) {
		current = current->next;
		positionTracker++;
		if (current->value == checkNumber) {
			return positionTracker;
		}
	}
	return 0;
}

void UnOrderedList::removeAll() {
	Node* current = head;
	while (current->next) {
		Node* toDelete = current;
		current = current->next;
		delete toDelete;
	}
	head = NULL;
}

bool UnOrderedList::isInList(const int checkNumber) {
	Node* current = head;

	while (current) {
		if (current->value == checkNumber) {
			return true;
		}
		current = current->next;
	}
	return false;
}


