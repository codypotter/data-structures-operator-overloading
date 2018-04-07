#include"UnOrderedList.h"
#include"Student.h"
#include<iostream>

using namespace std;

int main(void) {
	// test template with ints --------------------------------
	UnOrderedList<int> intList;
	intList.prepend(10);
	intList.prepend(20);
	intList.prepend(5);
	intList.append(15);
	intList.append(25);
	intList.print();

	cout << "5 is in position " << intList.find(5) << endl;
	cout << "15 is in position " << intList.find(15) << endl;
	cout << "20 is in position " << intList.find(20) << endl;
	cout << "8 is in position " << intList.find(8) << endl;

	intList.remove(15);
	intList.remove(5);
	intList.remove(25);
	intList.print();

	intList.removeAll();
	intList.print();
	cout << endl << endl;

	// test on list of chars --------------------------------
	UnOrderedList<char>* charList = new UnOrderedList<char>;
	charList->append('k');
	charList->append('s');
	charList->prepend('r');
	charList->prepend('o');
	charList->prepend('w');
	charList->print();

	charList->remove('r');
	charList->remove('w');
	charList->remove('s');
	charList->print();

	charList->removeAll();
	charList->print();
	delete charList;

	// test it on Students ------------------------------------
	UnOrderedList<Student> studentList;
	Student cody("Cody", 'A');
	studentList.append(Student("Julie", 'B'));
	studentList.print();
	studentList.prepend(cody);
	studentList.print();
	studentList.remove(cody);
	studentList.print();
	studentList.append(Student("Shelby", 'A'));
	studentList.prepend(Student("Dan", 'F'));
	studentList.print();
	studentList.removeAll();
	studentList.print();

	cin.ignore(999, '/n');
	return 0;
}