#pragma once
#include <string>
using namespace std;
class movie{
private:
    string title;
    string director;
    int year;
    double rating;


public:
    movie();
    void setTitle(string title);
    void setDirector(string director);
    void setYear(int year);
    void setRating(double rating);
    void print();

    string getTitle();
    string getDirector();
    int getYear();
    double getRating();
};