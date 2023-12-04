#pragma once
#include "Player.h"
#include <vector>
using namespace std;

class Casino {
public:
	static vector<Player*> people;
	static Player* currentPlayer;
	static void Home();
	static void Games();
	static void AddUser(string name);
	static void ATM();
	static void PlaySlots();
};