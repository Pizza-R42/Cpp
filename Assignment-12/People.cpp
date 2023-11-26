#include "People.h"
#include <iostream>
using namespace std;

void Person::Print() {
	cout << firstName << " " << lastName << " ID: " << id << endl;
}


void Person::SetFirstName(string firstName) {
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
Person::~Person(){}

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

Student::Student(string firstName, string lastName, int id, string major, string minor, double gpa) : Person(firstName, lastName, id) {
	SetMajor(major);
	SetMinor(minor);
	SetGPA(gpa);
}

void Employee::SetSalary(double salary) {
	if (salary < 0) {
		cout << "INVALID SALARY";
		return;
	}
	this->salary = salary;
}

double Employee::GetSalary() {
	return salary;
}

Employee::Employee(string firstName, string lastName, int id, double salary) : Person(firstName, lastName, id) {
	SetSalary(salary);
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
	cout << "Prof. " << lastName << " (" << id << ") [Dept.of " << department << "] ($" << salary << ")\n";
}

Instructor::Instructor(string firstName, string lastName, int id, string department, double salary) : Employee(firstName, lastName, id, salary), Person(firstName, lastName, id) {
	SetDepartment(department);
} 


GraduateStudent::GraduateStudent(string firstName, string lastName, int id, string major, string minor, double gpa, double salary) :
	Student(firstName, lastName, id, major, minor, gpa), Employee(firstName, lastName, id, salary), Person(firstName, lastName, id) {}

void GraduateStudent::Print() {
	cout << Student::lastName << ", " << Student::firstName << " (" << Student::id << ") [" << major << " Major] GPA: " << gpa << " ($" << salary << ")" << endl;
}