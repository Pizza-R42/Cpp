#include "People.h"
#include <string>
#include <iostream>
using namespace std;

int main()
{
    const int size = 6;
    

    Person* people[size]{
        new Student("Greg","Allen",123456,"Criminology","Psychology",3.2),
        new Student("Sam","Bell",124766,"Science","Optometry",3.8),
        new Instructor("Louise","Banks",423653,"Robotics",42000),
        new Instructor("Ikari","Williams",823764,"Neurology",58000),
        new GraduateStudent("Greg","Allen",194617,"Engineering","Cybersecurity",3.2,11000),
        new GraduateStudent("Bob","Barns",624185,"Eudication","Psychology",3.2,21000)
    };


    cout << "Everyone: \n";
    for (int i = 0; i < size; i++) {
        people[i]->Print();
    }
    cout << endl;

    cout << "Graduate Students: \n";
    for (int i = 0; i < size; i++) {
        GraduateStudent* grad = dynamic_cast<GraduateStudent*>(people[i]);
        if (grad != nullptr) {
            grad->Print();
        }
    }
    cout << endl;

    Employee* maxSalary = nullptr;
    for (int i = 0; i < size - 1; i++) {
        Employee* tmp = dynamic_cast<Employee*>(people[i]);
        if (tmp != nullptr) {
            if (maxSalary == nullptr || maxSalary->GetSalary() < tmp->GetSalary()) {
                maxSalary = tmp;
            }
        }
    }

    cout << "The employee with the highest salary:\n";
    maxSalary->Print();


    Employee* minSalary = nullptr;
    for (int i = 0; i < size - 1; i++) {
        Employee* tmp = dynamic_cast<Employee*>(people[i]);
        if (tmp != nullptr) {
            if (minSalary == nullptr || minSalary->GetSalary() > tmp->GetSalary()) {
                minSalary = tmp;
            }
        }
    }

    cout << "\nThe employee with the lowest salary:\n";
    minSalary->Print();


    for (int i = 0; i < size; i++) {
        delete people[i];
    }
}


