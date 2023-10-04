#include <iostream>
#include "product.h"
using namespace std;

int main()
{
	const int size = 6;
	product products[6];
	products[0] = product("iPhone 14", 685.99, 3.6);
	products[1] = product("Galaxy S22", 417.97, 4.2);
	products[2] = product("Xbox Series S", 259.00, 4.4);
	products[3] = product("PlayStation 5", 499.99, 4.8);
	products[4] = product("Dell XPS 17", 3137.97, 3.9);
	products[5] = product("MacBook Pro", 2099.00, 4.7);

	cout << "Welcome! Here are the products available for purchase:\n\n";
	for (int i = 0; i < size; i++) {
		products[i].print();
	}

	cout << endl << "Best value products under $500:\n\n";

	for (int i = 0; i < size; i++) {
		if (products[i].getPrice() <= 500) {
			products[i].print();
		}
	}

	cout << endl << "Everything's on sale! Here are the updated prices:\n\n";

	for (int i = 0; i < size; i++) {
		products[i].setPrice(products[i].getPrice() * 0.75);
		products[i].print();
	}
	return 0;
}


