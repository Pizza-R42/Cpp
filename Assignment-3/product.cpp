#include <iostream>
#include <string>
#include "product.h"
using namespace std;


product::product() {
	this->name = "NULL";
	this->price = 0;
	this->rating = 0;
}
product::product(string name, float price, float rating) {
	this->name = name;
	this->price = price;
	this->rating = rating;
}
string product::getName() { return name; }
float product::getPrice() { return price; }
float product::getRating() { return rating; }

void product::setPrice(float price) {
	this->price = price;
}

void product::print() {
	cout << name << " | $" << price << " | Rated " << rating << " / 5.0 stars\n";
}