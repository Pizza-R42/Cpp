#include <iostream>
#include <string>
#include "movie.h"
using namespace std;

const double max_rating = 10; 
movie::movie(){}
// Set
void movie::setTitle(string title){
    this->title = title;
}
void movie::setDirector(string director){
    this->director = director;
}
void movie::setYear(int year){
    this->year = year;
}
void movie::setRating(double rating){
    this->rating = rating;
}

void movie::print(){
    cout << title << " by " << director << " (" << year <<") " << "[" << rating << " / " << max_rating <<"]" << endl;
}
// Get
string movie::getTitle(){ return title; }
string movie::getDirector(){ return director; }
int movie::getYear(){ return year; }
double movie::getRating(){ return rating; }




