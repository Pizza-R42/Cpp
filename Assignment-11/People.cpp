#include "People.h"
using namespace std;

void Person::Print() {
	cout << firstName << " " << lastName << " ID: " << id << endl;
}


void Person::SetFirstName(string firstName){
	if (firstName == "") {
		cout << "FIRST NAME IS EMPTY";
		firstName = "NULL";
		return;
	}
	this->firstName = firstName;
}

void Person::SetLastName(string lastName) {
	if (lastName == "") {
		cout << "LAST NAME IS EMPTY";
		lastName = "NULL";
		return;
	}
	this->lastName = lastName;
}

void Person::SetID(int id) {
	if (id < 0) {
		cout << "ID IS INVALID";
		return;
	}
	this->id = id;
}


Person::Person(string firstName, string lastName, int id) {
	SetFirstName(firstName);
	SetLastName(lastName);
	SetID(id);
}

void Student::Print() {
	cout << lastName << ", " << firstName << " (" << id << ") [" << major << " Major / " << minor << " Minor] GPA: " << gpa << endl;
}


void Student::SetMajor(string major) {
	if (major == "") {
		cout << "MAJOR IS EMPTY";
		major = "NULL";
		return;
	}
	this->major = major;
}
void Student::SetMinor(string minor) {
	if (minor == "") {
		cout << "MINOR IS EMPTY";
		minor = "NULL";
		return;
	}
	this->minor = minor;
}
void Student::SetGPA(double gpa) {
	if (gpa < 0 || gpa > 5) {
		cout << "INVALID GPA";
		return;
	}
	this->gpa = gpa;
}

double Student::GetGPA() {
	return this->gpa;
}

Student::Student(string firstName, string lastName, int id, string major, string minor, double gpa) : Person(firstName, lastName, id){
	this->major = major;
	this->minor = minor;
	this->gpa = gpa;
}

void Instructor::SetDepartment(string department) {
	if (department == "") {
		cout << "DEPARTMENT IS EMPTY";
		department = "NULL";
		return;
	}
	this->department = department;
}

void Instructor::Print() {
	cout << "Prof. " << lastName << " (" << id << ") [Dept.of " << department << "]\n";
}

Instructor::Instructor(string firstName, string lastName, int id, string department) : Person(firstName, lastName, id) {
	this->department = department;
}
