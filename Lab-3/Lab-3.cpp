#include <iostream>
#include <string>
#include "movie.h"
using namespace std;

int main(){
    int count;
    movie* movies;

    cout << "How many movies would you like to log? ";
    cin >> count;
    cout << endl;
    if (count <= 0){
        cout << "Invalid Input!";
        return -1;
    }
    cout << "OK, please tell me about your top "<< count <<" favorite movies!" << endl;

    movies = new movie[count];

    for (int i=0; i<count; i++){
        cout << endl;
        string _title;
        string _director;
        int _year;
        double _rating;

        cin.ignore();
        cout << "Title: ";
        getline(cin, _title);
        cout << "Director: ";
        getline(cin, _director);
        cout << "Year: ";
        cin >> _year;
        if (_year < 1800 || _year > 2023){
            cout << "Invalid Input";
            delete[] movies;
            return -1;
        }
        cin.ignore();
        cout << "Rating: ";
        cin >> _rating;
        if (_rating < 0 || _rating > 10){
            cout << "Invalid Input";
            delete[] movies;
            return -1;
        }

        movies[i].setTitle(_title);
        movies[i].setDirector(_director);
        movies[i].setYear(_year);
        movies[i].setRating(_rating);
    }

    cout << endl << "Your Top " << count << " Movies Are:\n" << endl;

    for (int i=0; i<count; i++){
        movies[i].print();
    }
    
    delete[] movies;
    return 0;
}