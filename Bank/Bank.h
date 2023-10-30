#pragma once
#include "User.h"
#include <string>
using namespace std;
class Bank {
private:
	static float bankValue;
	static int userCount;

public:
	static float GetBankValue();
	static void AddMoney(float amount);
	static bool RemoveMoney(float amount);
	static int GetUserCount();
	static void CalculateUserCount();
};