#pragma once
#include <string>

using namespace std;

class Game {
private:
	string title;
	int sales;
	string platform;
	string release;
	string developer;
	string publisher;
public:
	Game();
	Game(string title, int sales, string platform, string release, string developer, string publisher);
	string GetTitle();
	int GetSales();
	string GetPlatform();
	string GetRelease();
	string GetDeveloper();
	string GetPublisher();
};