#include "Roster.h"
#include "DegreeType.h"
#include <string>

void Roster::parse(string studentData)
{
	DegreeType dp = NETWORK; /*making this the default...it only occures once*/
	if (studentData.at(8) == 'Y') dp = SECURITY; // last character in degreeType helps with ID of students
	else if (studentData.at(8) == 'E') dp = SOFTWARE;

	int rightSide = studentData.find(","); /*looks for comma in the long string*/
	string studentID = studentData.substr(0, rightSide); /*pulls the data found in front of the comma*/

	int leftSide = rightSide + 1; /*move beyond comma*/
	rightSide = studentData.find(",", leftSide);
	string firstName = studentData.substr(leftSide, rightSide - leftSide);

	leftSide = rightSide + 1; /*iterate*/
	rightSide = studentData.find(",", leftSide);
	string lastName = studentData.substr(leftSide, rightSide - leftSide);

	leftSide = rightSide + 1; /*iterate again*/
	rightSide = studentData.find(",", leftSide);
	string email = studentData.substr(leftSide, rightSide - leftSide);

	leftSide = rightSide + 1; /*iterate again*/
	rightSide = studentData.find(",", leftSide);
	int age = stod(studentData.substr(leftSide, rightSide - leftSide));

	leftSide = rightSide + 1; /*iterate again*/
	rightSide = studentData.find(",", leftSide);
	double sDays1 = stod(studentData.substr(leftSide, rightSide - leftSide));

	leftSide = rightSide + 1; /*iterate again*/
	rightSide = studentData.find(",", leftSide);
	double sDays2 = stod(studentData.substr(leftSide, rightSide - leftSide));

	leftSide = rightSide + 1; /*iterate again*/
	rightSide = studentData.find(",", leftSide);
	double sDays3 = stod(studentData.substr(leftSide, rightSide - leftSide));

	add(studentID, firstName, lastName, email, age, sDays1, sDays2, sDays3, dp);
}

void Roster::add(string studentID, string firstName, string lastName, string email, int age, double sDays1, double sDays2, double sDays3, DegreeType dp)
{
	double sDarr[3] = { sDays1, sDays2, sDays3 };

	classRosterArray[++lastIndex] = new Student(studentID, firstName, lastName, email, age, sDarr, dp);
}

void Roster::printAll()
{

	// for (int i = 0; i <= this->lastIndex; i++)(this->classRosterArray)[i]->print();

	Student::printHeader();
	for (int i = 0; i <= Roster::lastIndex; i++)
	{			
		cout << classRosterArray[i]->getID(); cout << '\t';
		cout << classRosterArray[i]->getFirstName(); cout << '\t';
		cout << classRosterArray[i]->getLastName(); cout << '\t';
		cout << classRosterArray[i]->getEmail(); cout << '\t';
		cout << classRosterArray[i]->getAge(); cout << '\t';
		cout << classRosterArray[i]->getDays()[0]; cout << '\t';
		cout << classRosterArray[i]->getDays()[1]; cout << '\t';
		cout << classRosterArray[i]->getDays()[2]; cout << '\t';
		cout << DegreeTypeString[classRosterArray[i]->getDegree()] << std::endl;

		classRosterArray[i]->print();
	}
}

void Roster::printByDegreeType(DegreeType dp)
{
	Student::printHeader();
	for (int i = 0; i <= Roster::lastIndex; i++)
	{
		if (Roster::classRosterArray[i]->getDegree() == dp) classRosterArray[i]->print();
	}
	cout << std::endl;
}

void Roster::printInvalidEmails()
{
	bool any = false;
	for (int i = 0; i <= Roster::lastIndex; i++)
	{
		string faultEmail = (classRosterArray[i]->getEmail());
		if (faultEmail.find('@') != string::npos || (faultEmail.find('.') != string::npos && faultEmail.find(' ') != string::npos))
		{
			any = true;
			cout << faultEmail << ": " << classRosterArray[i]->getEmail() << std::endl;
		}
	}
	if (!any) cout << "EMAILS ARE VALID" << std::endl;
}

void Roster::printAverageCourseDays()
{
	for (int i = 0; i <= Roster::lastIndex; i++)
	{
		cout << classRosterArray[i]->getID() << ": ";
		cout << (classRosterArray[i]->getDays()[0] + classRosterArray[i]->getDays()[1] + classRosterArray[i]->getDays()[2])/3.0 << std::endl;
	}
	cout << std::endl;
}

void Roster::removeByStudentID(string studentID)
{
	bool success = false;
	for (int i = 0; i <= Roster::lastIndex; i++)
	{
		if (classRosterArray[i]->getID() == studentID)
		{
			success = true;
			if (i < numStudents - 1)
			{
				Student* temp = classRosterArray[i];
				classRosterArray[i] = classRosterArray[numStudents - 1];
				classRosterArray[numStudents - 1] = temp;
			}
			Roster::lastIndex--; /*student is not deleted, merely removed from being viewed*/
		}
	}
	if (success)
	{
		cout << studentID << " has been removed from the local repository." << std::endl << std::endl;
		this->printAll(); /*all but rmoved student(s) will be displayed*/
	}
	else cout << studentID << " was not found." << std::endl << std::endl;
}

Roster::~Roster()
{
	cout << "Implementing Destructor Protocol" << std::endl << std::endl;
	for (int i = 0; i < numStudents; i++)
	{
		cout << "Removing student #" << i + 1 << std::endl;
		delete classRosterArray[i];
		classRosterArray[i] = nullptr;
	}
}