#include "User.h"
#include "Bank.h"
#include <string>
#include <fstream>
#include <iostream>
using namespace std;


User::~User() {
	this->name = "NULL";
	this->money = 0;
}
User::User() {
	this->name = "NULL";
	this->money = 0;
}
void User::PopulateUser(string name, float money, string password) {
	this->name = name;
	this->money = money;
	this->password = password;
}

string User::GetName() {
	return this->name;
}

float User::GetMoney() {
	return this->money;
}

void User::Deposit(float money) {
	this->money += money;
}

void User::Withdraw(float money) {
	if (this->money - money < 0) {
		cout << "You Dont Have Enough Money!\n";
		return;
	}
	this->money -= money;
}
void User::Loan(float amount) {
	if (amount > Bank::GetBankValue()) {
		cout << "Sorry the bank dose not have enough for the loan\n\n";
		return;
	}

	money -= amount;
	cout << "You have taken out a loan of $" << amount << ", and must pay back the amount in time.\n\n";
}

string User::GetPassword() {
	return password;
}
void User::ViewInfo() {
	cout << "> Name: " << name << " $" << money << endl;
	
}


void Admin::ViewInfo() {
	cout << "Bank Value: " << Bank::GetBankValue() << endl;
	cout << "User Count: " << Bank::GetUserCount() << endl;

}


Admin::Admin(string name, float money, string password) {
	this->name = name;
	this->password = password;
	this->money = money;
	
}

