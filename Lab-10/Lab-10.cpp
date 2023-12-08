#include <iostream>
#include <fstream>
#include <vector>
#include <set>
#include <string>
#include <algorithm>

using namespace std;

struct Element {
    int atomicNumber;
    string elementName;
};

bool compareNumber(Element& a, Element& b) {
    return a.atomicNumber < b.atomicNumber;
}

void part1() {
    vector<Element> periodicTable;
    ifstream inputFile("PeriodicTable.csv");

    if (!inputFile.is_open()) {
        cout << "Error opening file." << endl;
        return;
    }

    string line;
    while (getline(inputFile, line)) {
        size_t commaPos = line.find(',');

        if (commaPos == string::npos) {
            cout << "Error reading line: " << line << endl;
            return;
        }

        Element element;
        element.atomicNumber = stoi(line.substr(0, commaPos));
        element.elementName = line.substr(commaPos + 1);

        periodicTable.push_back(element);
    }

    inputFile.close();

    sort(periodicTable.begin(), periodicTable.end(), compareNumber);

    for (Element element : periodicTable) {
        cout << element.atomicNumber << " - " << element.elementName << endl;
    }
}

void part2() {
    set<string> uniqueChemists;
    ifstream inputFile("Chemists.txt");

    if (!inputFile.is_open()) {
        cerr << "Error opening file." << endl;
        return;
    }

    string chemistName;
    while (getline(inputFile, chemistName)) {
        uniqueChemists.insert(chemistName);
    }

    inputFile.close();
    cout << "There are " << uniqueChemists.size() << " unique names in this file. \n";
   
    return;
}

int main() {
    part1();
    cout << endl;
    part2();
    

    return 0;
}