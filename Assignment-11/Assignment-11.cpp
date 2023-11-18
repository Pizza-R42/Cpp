#include "People.h"
#include <iostream>

int main()
{
    const int size = 8;
    
    Person* people[size]{
        new Student("Greg","Allen",123456,"Criminology","Psychology",3.2),
        new Student("Rick","Deckard",394623,"Philosophy","Mathematics",4.0),
        new Student("Eleanor","Arroway",342356,"Geology","Science",2.9),
        new Student("Sam","Bell",124766,"Science","Optometry",3.8),
        new Student("Paul","Atreides",936562,"Communication","Philosophy ",1.9),
        new Instructor("Louise","Banks",423653,"Robotics"),
        new Instructor("Ikari","Williams",823764,"Neurology"),
        new Instructor("Cooper","Bark",123975,"Agriculture")
    };

    double gpaTotal = 0;
    int studentSize = 0;
    for (int i = 0; i < size; i++) {
        people[i]->Print();

        Student* student = dynamic_cast<Student*>(people[i]);
        if (student != nullptr) {
            gpaTotal += student->GetGPA();
            studentSize++;
        }
    }
    cout << endl << "The average student GPA is " << gpaTotal / studentSize << endl;

    for (int i = 0; i < size; i++) {
        delete people[i];
    }
    
}
