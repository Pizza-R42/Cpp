// DO NOT MODIFY THIS FILE IN ANY WAY
#include <string>
#include <iomanip>
#include "movie.h"
movie::movie(std::string title, std::string director, int year, double rating) {
this->title = title;
this->director = director;
this->year = year;
this->rating = rating;
}
std::string movie::get_title() {
return title;
}
std::string movie::get_director() {
return director;
}
int movie::get_year() {
return year;
}
double movie::get_rating() {
return rating;
}
void movie::set_rating(double rating) {
if (rating >= 0.5 && rating <= 5.0) {
this->rating = rating;
}
}
void movie::print() {
std::cout << title
<< " ("
<< year
<< ") by "
<< director
<< " [Rated "
<< std::setprecision(2)
<< std::fixed
<< std::showpoint
<< rating
<< " / 5.00]"
<< std::endl;
}
