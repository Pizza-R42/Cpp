#include "Items.h"
#include <iomanip>
#include <iostream>

using namespace std;

Item::Item() {
	price = 0;
	model = "NULL";
	manufacturer = "NULL";
}
Item::Item(double price, string model, string manufacturer) {
	this->price = price;
	this->model = model;
	this->manufacturer = manufacturer;
}
void Item::SetPrice(double price) { this->price = price; }
void Item::SetModel(string model) { this->model = model; }
void Item::SetManufacturer(string manufacturer) { this->manufacturer = manufacturer; }

double Item::GetPrice() { return price; }
string Item::GetModel() { return model; }
string Item::GetManufacturer() { return manufacturer; }

Computer::Computer(double price, string model, string manufacturer, double storage) : Item(price, model, manufacturer) {
	this->storage = storage;
}
Television::Television(double price, string model, string manufacturer, double size) : Item(price, model, manufacturer) {
	this->size = size;
}

Laptop::Laptop(double price, string model, string manufacturer, double storage, double battery) : Computer(price, model, manufacturer, storage) {
	this->battery = battery;
}

Desktop::Desktop(double price, string model, string manufacturer, double storage) : Computer(price, model, manufacturer, storage){}



void Item::Print() {
	cout << "Base Item Print";
}

void Computer::Print() {
	cout << "The " << manufacturer << " " << model << " ($" << fixed << setprecision(2) << price << ") has " << setprecision(0) << storage << " GB of storage\n";
}

void Television::Print() {
	cout << "The " << manufacturer << " " << model << " Television ($" << fixed << setprecision(2) << price << ") is " << setprecision(0) <<  size << "\"\n";
}

void Laptop::Print() {
	cout << "The " << manufacturer << " " << model << " Laptop ($" << fixed << setprecision(2) << price << ") has " << setprecision(0) << storage << " GB of storage and " << battery << " hours of battery life\n";
}