#pragma once
#include <iostream>
#include <iomanip>
#include "DegreeType.h"

using std::string;
using std::cout;


class Student
{
public:
	const static int daysArraySize = 3;

private:
	string studentID;
	string firstName;
	string lastName;
	string email;
	int age;
	double days[daysArraySize];
	DegreeType degreeType;

public: //	constructor
	Student();
	Student(string studentID, string firstName, string lastName, string email, int age, double days[], DegreeType degreeType);
	~Student(); // destructor

	// getters

	string getID();
	string getFirstName();
	string getLastName();
	string getEmail();
	int getAge();
	double* getDays();
	DegreeType getDegree();

	// setters

	void setID(string ID);
	void setFirstName(string firstName);
	void setLastName(string lastName);
	void setEmail(string email);
	void setAge(int age);
	void setDays(double days[]);
	void setDegree(DegreeType dp);

	static void printHeader();

	void print(); // display student data
};