#pragma once
#include <string>
#include <iostream>
using namespace std;


class Person {
protected:
	string firstName;
	string lastName;
	int id;
public:
	Person(string firstName, string lastName, int id);
	virtual void Print();
	void SetFirstName(string firstName);
	void SetLastName(string lastName);
	void SetID(int id);
};


class Student : public Person {
protected:
	string major;
	string minor;
	double gpa;
public:
	Student(string firstName, string lastName, int id, string major, string minor, double gpa);
	void Print() override;
	void SetMajor(string major);
	void SetMinor(string minor);
	void SetGPA(double gpa);
	double GetGPA();
};



class Instructor : public Person {
protected:
	string department;
public:

	Instructor(string firstName, string lastName, int id, string department);
	void Print() override;
	void SetDepartment(string department);
};