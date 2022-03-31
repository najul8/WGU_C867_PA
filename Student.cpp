#include "Student.h"

Student::Student()
{
	this->studentID = "";
	this->firstName = "";
	this->lastName = "";
	this->email = "";
	this->age = 0;
	for (int i = 0; i < daysArraySize; i++) this->days[i] = 0;
	this->degreeType = DegreeType::NETWORK;
}


// Constructor
Student::Student(string studentID, string firstName, string lastName, string email, int age, double days[], DegreeType dp)
{
	this->studentID = studentID;
	this->firstName = firstName;
	this->lastName = lastName;
	this->email = email;
	this->age = age;
	for (int i = 0; i < daysArraySize; i++) this->days[i] = days[i];
	this->degreeType = dp;
}

// destructor
Student::~Student() {}

string Student::getID() { return this->studentID; }
string Student::getFirstName() { return this->firstName; }
string Student::getLastName() { return this->lastName; }
string Student::getEmail() { return this->email; }
int Student::getAge() { return this->age; }
double* Student::getDays() { return this->days; }
DegreeType Student::getDegree() { return this->degreeType; }

void Student::setID(string ID) { this->studentID = studentID; }
void Student::setFirstName(string firstName) {this->firstName = firstName; }
void Student::setLastName(string lastName) {this->lastName = lastName; }
void Student::setEmail(string email) {this->email = email; }
void Student::setAge(int age) {this->age = age; }
void Student::setDays(double days[])
{
	for (int i = 0; i < daysArraySize; i++) this->days[i] = days[i];
}
void Student::setDegree(DegreeType dp) {this->degreeType = degreeType; }

void Student::printHeader()
{
	cout << "Output format: Student ID|First Name|Last Name|Email|Age|Days in Course|Degree Program\n";
}

void Student::print()
{
	cout << this->getID() << '\t';
	cout << this->getFirstName() << '\t';
	cout << this->getLastName() << '\t';
	cout << this->getEmail() << '\t';
	cout << this->getAge() << '\t';
	cout << this->getDays()[0] << ', ';
	cout << this->getDays()[1] << ', ';
	cout << this->getDays()[2] << '\t';
	cout << DegreeTypeString[this->getDegree()] << '\n';
}