#pragma once
#include <string>
#include <iostream>
using namespace std;

class Item {
protected:
	double price;
	string model;
	string manufacturer;
public:
	Item();
	Item(double price, string model, string manufacturer);
	virtual void Print();

	void SetPrice(double price);
	void SetModel(string model);
	void SetManufacturer(string manufacturer);

	double GetPrice();
	string GetModel();
	string GetManufacturer();
};

class Computer : public Item {
protected:
	double storage;
public:
	Computer(double price, string model, string manufacturer, double storage);
	void Print() override;
};

class Television : public Item {
protected:
	double size;
public:
	Television(double price, string model, string manufacturer, double size);
	void Print() override;
};

class Laptop : public Computer {
protected:
	double battery;
public:
	Laptop(double price, string model, string manufacturer, double storage, double battery);
	void Print() override;
};

class Desktop : public Computer {
public:
	Desktop(double price, string model, string manufacturer, double storage);

};

