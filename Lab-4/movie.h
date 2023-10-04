// DO NOT MODIFY THIS FILE IN ANY WAY
#pragma once
#include <iostream>
#include <string>
class movie {
private:
std::string title;
std::string director;
int year;
double rating;
public:
movie(std::string title, std::string director, int year, double rating);
std::string get_title();
std::string get_director();
int get_year();
double get_rating();
void set_rating(double rating);
void print();
};
