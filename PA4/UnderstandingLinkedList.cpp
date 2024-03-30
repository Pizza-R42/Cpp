#include <iostream>
#include <list>
#include <iterator>
using namespace std;

static void print(list<int> &numbers) { // printing the content of the list
	list<int>::iterator it = numbers.begin();
	while (it != numbers.end()) {
		cout << *it << " ";
		it++;
	}
	cout << endl;
}

static void remove(list<int> &numbers, int index) { // remove node at index
	if (numbers.size() == 0)
		return; // nothing to remove
	if (index == 0)
		numbers.pop_front(); // remove node at index 0
	else if (index == numbers.size() - 1)
		numbers.pop_back(); // remove node at last index
	else {
		int i = 0;
		list<int>::iterator it = numbers.begin();
		while (it != numbers.end()) {
			if (i == index) { // once i = index, we are at desired node; delete it
				numbers.erase(it);
				return;
			}
			it++;
			i++;
		}
	}
}

void play() {
	list<int> numbers = list<int>(); // creating an integer list
	numbers.push_back(15); // adding a number at the end
	numbers.push_back(99);
	numbers.push_back(-10);
	numbers.push_back(100);
	numbers.push_front(0); // adding a number at the front
	numbers.push_front(57);
	numbers.push_front(-99);
	print(numbers); // prints: -99 57 0 15 99 -10 100

	remove(numbers, 0);
	print(numbers); // prints: 57 0 15 99 -10 100

	remove(numbers, numbers.size() - 1);
	print(numbers); // prints: 57 0 15 99 -10

	remove(numbers, 2);
	print(numbers); // prints: 57 0 99 -10
}

int main() {
	play();
	return 0;
}

