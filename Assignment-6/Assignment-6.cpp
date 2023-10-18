#include <iostream>
#include <fstream>
#include "Game.h"
using namespace std;

Game* games;
int fileLength;
string path = "videogames.csv";
string sortedPath = "sortedgames.csv";

int GetFileSize() {
    ifstream file;
    file.open(path);
    if (!file.is_open()) {
        return 0;
    }
    string line;

    int rows = 0;
    while (getline(file, line)) {
        rows++;
    }
    file.close();
    return rows;
}

bool ReadFile() {
    games = new Game[fileLength];

    ifstream file;
    file.open(path);
    if (!file.is_open()) {
        cout << "Error opening file!";
        file.close();
        return false;
    }

    string line;
    getline(file, line);//Ignore header line
    for (int i = 0; i < fileLength; i++) {

        string title, platform, release, developer, publisher;
        string salesStr;
        int sales;

        getline(file, title, ',');
        getline(file, salesStr, ',');
        getline(file, platform, ',');
        getline(file, release, ',');
        getline(file, developer, ',');
        getline(file, publisher);

        sales = stoi(salesStr);
        games[i] = Game(title, sales, platform, release, developer, publisher);
    }
    file.close();
    return true;
}

void AlphabeticalSort() {
    for (int j = 0; j < fileLength; j++) {
        for (int i = j; i < fileLength; i++) {
            if (games[i].GetTitle() < games[j].GetTitle()) {
                swap(games[i], games[j]);
            }
        }
    }
}

void MakeSortedCSV() {
    ofstream file;
    file.open(sortedPath);
    file << "Title,Sales,Platform(s),Initial release date,Developer(s),Publisher(s)\n";
    for (int i = 0; i < fileLength; i++) {
        file << games[i].GetTitle() + "," << games[i].GetSales() << "," + games[i].GetPlatform() + "," + games[i].GetRelease() + "," + games[i].GetDeveloper() + "," + games[i].GetPublisher() + "\n";
    }
    file.close();
}

int main()
{
    cout << "Reading data from CSV file...\n";
    fileLength = GetFileSize() -1;
    if (!ReadFile()) {
        delete[] games;
        return -1;
    }
    cout << "Done!\n\n";

    cout << "Sorting data...\n";
    AlphabeticalSort();
    cout << "Done!\n\n";

    cout << "Writing data to CSV file...\n";
    MakeSortedCSV();
    cout << "Done!";

    delete[] games;
    
}


