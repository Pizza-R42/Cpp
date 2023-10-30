#include <iostream>
#include <fstream>
#include <string>
#include "Bank.h"
#include "User.h"
using namespace std;

string adminName = "admin";
string adminPassword = "123";

ifstream fileInput;
ofstream fileOutput;
string path = "Users.csv";

User** users;
User* currentUser;

bool HomeOptions();
void UpdateFile();
void SortByValue();



void PopulateUsers() {
    Bank::CalculateUserCount();

    fileInput.open(path);
    if (!fileInput.is_open()) {
        UpdateFile();
        PopulateUsers();
        return;
    }
    
    
    delete[] users;
    users = new User*[Bank::GetUserCount()+1];
   

    string line;
    getline(fileInput, line);
    for (int i = 0; i < Bank::GetUserCount(); i++) {
        
        string name;
        string moneyStr;
        string password;

        
        getline(fileInput, name, ',');
        getline(fileInput, moneyStr, ',');
        getline(fileInput, password);
        
        float money = stof(moneyStr);
        

        if (i == 0) { //Admin

            users[i] = new Admin(adminName, money, adminPassword);
            Bank::AddMoney(money);
  
            continue;
        }
        users[i] = new User();

        users[i]->PopulateUser(name, money, password);
        
    }
    
    fileInput.close();
}

void UpdateFile() {
    SortByValue();
    fileOutput.open(path);
    if (!fileOutput.is_open()) {
        cout << "Not Open\n";
        return;
    }
    
   
    fileOutput << "(Name),(Money),(Password)\n" << adminName << "," << Bank::GetBankValue() << "," << adminPassword << "\n";
    for (int i = 1; i < Bank::GetUserCount(); i++) {
        fileOutput << users[i]->GetName() << "," << users[i]->GetMoney() << "," << users[i]->GetPassword() << "\n";
    }
    fileOutput.close();
    Bank::CalculateUserCount();
}

bool Register() {
    string name;
    string password;
    
    while (true) {
        cout << "Enter Name to Register: ";
        getline(cin, name);

        if (name == "" || name.find(',') <= name.length()) {
            cout << "Invalid Name!\n";
            continue;
        }
        break;
    }
    for (int i = 0; i < Bank::GetUserCount(); i++) {
        if (users[i]->GetName() == name) {
            cout << "Name Alreay Exists\n";
            return false;
        }
    }

    cout << "Enter A Password: ";
    getline(cin, password);
    
    
    fileInput.open(path);
    if (!fileInput.is_open()) {
        UpdateFile();
    }
    fileInput.close();

    fileOutput.open(path, ios::app);
    if (!fileOutput.is_open()) {
        cout << "File Not Opened";
        return false;
    }

    fileOutput << name << "," << "0" << "," << password << "\n";
    fileOutput.close();
    PopulateUsers();

    cout << "You Have Registerd As: " << name;

    while (!HomeOptions()) {
        cout << "Invalid Option!\n\n";
    }
    return true;
}



bool DepositMoney() {
    float money;
    string moneyStr;

    int decimalCount = 0;
    cout << "How much would you like to deposit?\n  $";
    //cin.ignore();
    getline(cin, moneyStr);

    if (moneyStr == "") {
        return false;
    }

    for (char c : moneyStr) {
        if (c == '.') {
            decimalCount++;
            if (decimalCount > 1) {
                return false; 
            }
        }
        else if (!isdigit(c)) {
            return false;
        }
        
    }
    

    money = stof(moneyStr);
    currentUser->Deposit(money);
    Bank::AddMoney(money);
    cout << "\nDepositied $" << money << "\n\n";

    return true;
}

bool WithdrawMoney() {
    float money;
    string moneyStr;

    int decimalCount = 0;
    cout << "How much would you like to withdraw?\n  $";
    getline(cin, moneyStr);

    if (moneyStr == "") {
        return false;
    }

    for (char c : moneyStr) {
        if (c == '.') {
            decimalCount++;
            if (decimalCount > 1) {
                return false;
            }
        }
        else if (!isdigit(c)) {
            return false;
        }

    }


    money = stof(moneyStr);
    if (money > currentUser->GetMoney()) {
        cout << "\nYOU DO NOT HAVE ENOUGH MONEY\n\n";
        return true;
    }
    
    if (!Bank::RemoveMoney(money)) {
        return true;
    }
    currentUser->Withdraw(money);

    cout << "\nWithdrawed $" << money << "\n\n";

    return true;
}

bool TakeLoan() {
    float money;
    string moneyStr;

    int decimalCount = 0;
    cout << "How much would you like to take out for a loan?\n  $";
    cin.ignore();
    getline(cin, moneyStr);

    if (moneyStr == "") {
        return false;
    }

    for (char c : moneyStr) {
        if (c == '.') {
            decimalCount++;
            if (decimalCount > 1) {
                cout << "\nINVALID INPUT\n\n";
                return false;
            }
        }
        else if (!isdigit(c)) {
            cout << "\nINVALID INPUT\n\n";
            return false;
        }

    }


    money = stof(moneyStr);


    if (!Bank::RemoveMoney(money)) {
        return true;
    }

    currentUser->Loan(money);

    return true;
}

void Logout() {
    UpdateFile();
    currentUser = nullptr;
    cout << "You Have Logged Out\n\n";
    while (!HomeOptions()) {}
}

void LoggedIn() {
    while (true) {
        int choice;
        cout << "What Would You Like to do? \n";
        cout << "1: See Acount Details\n2: Deposit Money\n3: Withdraw Money\n4: Take out a Loan\n5: Log Out\n";
        cout << "Enter Your Option: ";
        cin >> choice;
        if (choice <= 0 || choice > 5) {
            cout << "\nINVALID CHOICE!\n\n";
            continue;
        }

        switch (choice) {
        case 1:
            cout << endl;
            currentUser->ViewInfo();
            cout << endl;
            break;
        case 2:
            cin.ignore();
            while (!DepositMoney()) {
                cout << "\nINVALID INPUT\n\n";
            }
            break;
        case 3:
            cin.ignore();
            while (!WithdrawMoney()) {
                cout << "\nINVALID INPUT\n\n";
            }
            break;
        case 4:
            while (!TakeLoan()) {}
            break;

        case 5:
            goto end;
            break;
        default:
            break;
        }

    }
end:
    Logout();
}



bool Login() {
    cout << "\nEnter Login Name: ";
    string name;
    
    getline(cin, name);
    if (name == "" || name.find(',') <= name.length()) {
        cout << "Invalid Name!\n";
        return false;
    }

    for (int i = 0; i < Bank::GetUserCount(); i++) {
        if (users[i]->GetName() == name) {

            while (true) {
                string pass;
                cout << "Enter your Password: ";
                getline(cin, pass);
                if (pass != users[i]->GetPassword()) {
                    cout << "\nINCORRECT PASSWORD\n\n";
                    continue;
                }
                break;
            }



            currentUser = users[i];
            cout << "\n___Logged in as " << name << "___\n\n";

            LoggedIn();

            return true;
        }
    }
    return false;
}

bool HomeOptions() {
    int choice;
    cout << "_Welcome To The Bank_\nWhat would you like to do?\n\n1: Login\n2: Register\n3: Close Program\n\n>";
    cout << "Enter Your Option: ";   
    cin >> choice;
    if (choice <= 0 || choice > 3) { 
        return false;
    }

    switch (choice)
    {
    case 1:
        cin.ignore();
        while (!Login()) {
            cout << "Name Not Found!\n";
            cout << "Would You Like To Register? [y/n]: ";
            string inp;
            getline(cin, inp);
            if (inp == "" || inp == "y" || inp == "Y") {
                cout << "Registering...\n";
                while (!Register()) {

                }
                break;
            }
        }
        break;
    case 2:
        cin.ignore();
        while (!Register()) {}
        break;
    case 3:
        break;
        UpdateFile();
        for (int i = 0; i < Bank::GetUserCount(); i++) {
            delete users[i];
        }
        delete[] users;
    default:
        break;
    }
    return true;
}

void SortByValue() {//Bubble sort
    int size = Bank::GetUserCount();
    bool swapped;
    for (int i = 0; i < size; i++) {
        swapped = false;
        for (int j = 1; j < size - i - 1; j++) {
            if (users[j]->GetMoney() < users[j + 1]->GetMoney()) {
                swap(users[j], users[j + 1]);
                swapped = true;
            }
        }
        if (swapped == false) {
            break;
        }
    }
}


//Bank Class
void Bank::CalculateUserCount() {
    int count = 0;
    fileInput.open(path);
    if (!fileInput.is_open()) {
        return;
    }
    string line;
    getline(fileInput, line);//Header Line
    while (getline(fileInput, line)) {
        count++;
    }
    fileInput.close();

    userCount = count;
}

int Bank::GetUserCount() {
    return userCount;
}
int Bank::userCount = 0;

float Bank::bankValue;

float Bank::GetBankValue() {
    return bankValue;
}
void Bank::AddMoney(float amount) {
    bankValue += amount;
}

bool Bank::RemoveMoney(float amount) {
    if (amount > bankValue) {
        cout << "\nSorry, the bank dose not currently have that much money\n\n";
        return false;
    }
    bankValue -= amount;
    return true;
}


int main()
{
    PopulateUsers();
    while (!HomeOptions()) {
        cout << "Invalid Option!\n\n";
    }

    UpdateFile();
    for (int i = 0; i < Bank::GetUserCount(); i++) {
        delete users[i];
    }
    delete[] users;
   
}
