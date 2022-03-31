#pragma once
#include "Student.h"

class Roster

{
private:
	int lastIndex = -1;
	const static int numStudents = 5;
	Student* classRosterArray[numStudents];

public:
	void parse(string row);

	void add(string studentID, string firstName, string lastName, string email, int age, double sDays1, double sDays2, double sDays3, DegreeType dp);

	void printAll();
	void printByDegreeType(DegreeType dp);
	void printInvalidEmails();
	void printAverageCourseDays();
	void removeByStudentID(string studentID);
	~Roster();
};