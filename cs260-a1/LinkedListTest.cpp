#include"UnOrderedList.h"
#include<iostream>

using namespace std;

int main(void) {
	UnOrderedList list;
	list.append(1);
	list.append(2);
	list.append(3);
	list.append(1);
	list.append(1);
	list.print();

	list.remove(7);
	list.print();

	list.prepend(32);
	list.print();

	return 0;
}