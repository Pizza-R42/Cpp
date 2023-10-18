#include "Game.h"
#include <string>
#include <iostream>
using namespace std;
Game::Game() {

}

Game::Game(string title, int sales, string platform, string release, string developer, string publisher) {
	this->title = title;
	this->sales = sales;
	this->platform = platform;
	this->release = release;
	this->developer = developer;
	this->publisher = publisher;
}

string Game::GetTitle() { return title; }
int Game::GetSales() { return sales; }
string Game::GetPlatform() { return platform; }
string Game::GetRelease() { return release; }
string Game::GetDeveloper() { return developer; }
string Game::GetPublisher() { return publisher; }
