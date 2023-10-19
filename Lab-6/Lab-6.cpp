#include "Items.h"
#include <iostream>
using namespace std;

const int itemCount = 9;
Item* items[itemCount]{
	new Television(1097.99, "Q60B", "Samsung", 75),
	new Television(179.99, "F20", "Insignia", 32),
	new Television(14997.99, "QN90A", "Samsung", 98),

	new Computer(2229.39, "Z2G4", "HP", 1024),
	new Computer(699.99, "Inspiron 3910", "Dell", 256),
	new Computer(204.62, "M92p", "Lenovo", 3072),

	new Laptop(1093.60, "EliteBook 850 G8", "HP", 512, 4),
	new Laptop(1879.00 , "XPS 17", "Dell", 1024, 10),
	new Laptop(169.99, "A4-9120e", "Gateway", 64, 8)
};

void PrintArr() {
	for (int i = 0; i < itemCount; i++) {
		items[i]->Print();
	}
}

void Sale() {
	for (int i = 0; i < itemCount; i++) {
		if (dynamic_cast<Computer*>(items[i]) == nullptr) {
			continue;
		}
		items[i]->SetPrice(items[i]->GetPrice() * 0.75);
	}
}

int main()
{
	cout << "ITEMS AVAILABLE FOR SALE:\n\n";
	PrintArr();
	cout << "\nALL COMPUTERS ARE ON SALE THIS WEEKEND! 25 % OFF!\n\n";
	Sale();
	PrintArr();
	
	//Delete Memory
	for (int i = 0; i < itemCount; i++) {
		delete items[i];
	}
}

