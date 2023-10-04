#include "movie.h"
#include <iostream>
#include <algorithm>
using namespace std;
void part_one(movie movies[], int num_movies) {
	cout << "Please enter a movie to search for\n > ";
	string input;
	getline(cin, input);

	for (int i = 0; i < num_movies; i++) {
		if (movies[i].get_title() == input) {
			movies[i].print();
			break;
		}
		if (i == num_movies - 1) {
			cout << "Movie not found.\n";
		}
	}
	cout << endl;
}
void part_two(movie movies[], int num_movies) {
	movie* high = &movies[0];
	movie* low = &movies[0];
	for (int i = 1; i < num_movies; i++) {
		if (movies[i].get_rating() > high->get_rating()) {
			high = &movies[i];
		}

		if (movies[i].get_rating() < low->get_rating()) {
			low = &movies[i];
		}
	}

	cout << "Highest rated movie:\n";
	high->print();
	cout << endl;
	cout << "Lowest rated movie:\n";
	low->print();
	cout << endl << endl;
}
void part_three(movie movies[], int num_movies) {
	for (int j = 0; j < num_movies; j++) {
		for (int i = 0; i < num_movies; i++) {
			if (movies[i].get_year() < movies[j].get_year()) {
				swap(movies[i], movies[j]);
			}
		}
	}

	for (int i = 0; i < num_movies; i++) {
		movies[i].print();
	}
}
#pragma region DO NOT MODIFY ANY CODE IN THIS REGION
int main() {
	const int num_movies = 15;
	movie* movies = new movie[num_movies]{
	movie("12 Angry Men", "Sidney Lumet", 1957, 4.52),
	movie("1917", "Sam Mendes", 2019, 4.08),
	movie("2001: A Space Odyssey", "Stanley Kubrick", 1968, 4.29),
	movie("Blade Runner", "Ridley Scott", 1982, 4.09),
	movie("Blade Runner 2049", "Denis Villeneuve", 2017, 4.10),
	movie("The Dark Knight", "Christopher Nolan", 2008, 4.44),
	movie("Dunkirk", "Christopher Nolan", 2017, 3.79),
	movie("The Godfather", "Francis Ford Coppola", 1972, 4.54),
	movie("Interstellar", "Christopher Nolan", 2014, 4.23),
	movie("Nausicaa of the Valley of the Wind", "Hayao Miyazaki",
	1984, 4.07),
	movie("Paths of Glory", "Stanley Kubrick", 1957, 4.34),
	movie("Princess Mononoke", "Hayao Miyazaki", 1997, 4.33),
	movie("Whiplash", "Damien Chazelle", 2014, 4.39),
	movie("Whisper of the Heart", "Yoshifumi Kondo", 1995, 4.12),
	movie("The Wind Rises", "Hayao Miyazaki", 2013, 4.00),
	};
	part_one(movies, num_movies);
	part_two(movies, num_movies);
	part_three(movies, num_movies);
	delete[] movies;
	return 0;
}
#pragma endregion
