#pragma once
#include <string>
using namespace std;

class product {
private:
	string name;
	float price;
	float rating;
public:
	product();
	product(string name, float price, float rating);
	string getName();
	float getPrice();
	float getRating();
	void setPrice(float price);
	void print();

};