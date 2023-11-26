#pragma once
#include <string>
using namespace std;


class Person {
protected:
	string firstName;
	string lastName;
	int id;
public:
	Person(string firstName, string lastName, int id);
	virtual ~Person();
	virtual void Print();
	void SetFirstName(string firstName);
	void SetLastName(string lastName);
	void SetID(int id);
};

class Student : virtual public Person {
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

class Employee : virtual public Person {
protected:
	double salary;
public:
	Employee(string firstName, string lastName, int id, double salary);
	void SetSalary(double salary);
	double GetSalary();
};

class Instructor : public Employee {
protected:
	string department;
public:
	Instructor(string firstName, string lastName, int id, string department, double salary);
	void Print() override;
	void SetDepartment(string department);
};

class GraduateStudent : public Employee, public Student {
public:
	GraduateStudent(string firstName, string lastName, int id, string major, string minor, double gpa, double salary);
	void Print() override;
};