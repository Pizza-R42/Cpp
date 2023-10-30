#pragma once
#include <string>
using namespace std;

class User {
protected:
	string name;
	float money;
	string password;
public:
	virtual ~User();
	User();
	void PopulateUser(string name, float money, string password);

	string GetName();
	float GetMoney();
	virtual void ViewInfo();

	void Withdraw(float money);
	void Deposit(float money);

	void Loan(float amount);

	string GetPassword();
};

class Admin : public User {
public:
	Admin(string name, float money, string password);
	void ViewInfo() override;
	
};