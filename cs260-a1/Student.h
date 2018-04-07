/*
	Program:	CS-260 A1
	Author:		Cody Potter
	Date:		2018-04-06
	Purpose:	Student class for testing templates, 
				operator overloading, and linked lists
*/
#pragma once
#include<iostream>
#include<string>

using namespace std;

class Student {
public:
	Student(const string name = "anonymous", char letterGrade = 'W');

	friend bool operator== (const Student& stu1, const Student& stu2);
	friend ostream& operator<< (ostream& stream, const Student& student);
private:
	string name;
	char letterGrade;
};

bool operator== (const Student& stu1, const Student& stu2) {
	if (stu1.name == stu2.name && stu1.letterGrade == stu2.letterGrade) {
		return true;
	}
	return false;
}

ostream& operator<< (ostream& stream, const Student& student) {
	stream << student.name;
	stream << " (" << student.letterGrade << ")";
	return stream;
}

Student::Student(string newName, char newLetterGrade) {
	name = newName;
	letterGrade = newLetterGrade;
}
