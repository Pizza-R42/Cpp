#include "Game.h"
#include "Casino.h"
#include "Input.h"
#include <vector>
#include <string>
#include <iostream>
using namespace std;


Slots::Slots(Player* player) {
    credits = 0;
    this->player = player;
    InitializeReels();
}

void Slots::ExitGame() {
    Game::ExitGame();
    player->AddCash(credits);
    credits = 0;
    Casino::Home();
}

void Slots::InitializeReels() {
    for (int i = 0; i < 3; ++i) {
        reels[i] = { CHERRY, LEMON, ORANGE, PLUM, BELL, BAR, SEVENS };
        landedReels[i] = SEVENS;
    }
    
}

void Slots::Spin() {
    srand(static_cast<unsigned int>(time(nullptr)));
    cout << endl;
    for (int i = 0; i < 3; ++i) {
        int randomIndex = rand() % reels[i].size();
        landedReels[i] = reels[i][randomIndex];
        cout << "[" << GetSymbolName(reels[i][randomIndex]) << "] ";
    }
    
    cout << "\n\n";
}

int Slots::CheckWin(int spinAmt) {
    int cherryCount = 0;
    for (int i = 0;  i < 3; i++) {
        if (landedReels[i] == CHERRY) {
            cherryCount++;
        }
    }
    if (landedReels[0] == SEVENS && landedReels[1] == SEVENS && landedReels[2] == SEVENS) {
        return 100 * spinAmt;
    }
    if (landedReels[0] == BAR && landedReels[1] == BAR && landedReels[2] == BAR) {
        return 20 * spinAmt;
    }
    if (landedReels[0] == CHERRY && landedReels[1] == CHERRY && landedReels[2] == CHERRY) {
        return 10 * spinAmt;
    }
    if (cherryCount == 2) {
        return 5 * spinAmt;
    }
    if (cherryCount == 1) {
        return 2 * spinAmt;
    }

    return 0;
}

string Slots::GetSymbolName(Symbol symbol) {
    string symbolNames[MAX_SYMBOLS] = { "CHERRY", "LEMON", "ORANGE", "PLUM", "BELL", "BAR", "SEVEN" };
    return symbolNames[symbol];
}
void Slots::PlayRound(int spinCost) {
    if (credits <= 0) {
        cout << "You Have No Credits Left!\n\n";
        ExitGame();
    }
    credits -= spinCost;
    cout << "Press Enter to spin the reels...";
    cin.ignore();
    Spin();
    int winAmt = CheckWin(spinCost);
    if (winAmt > 0) {

        cout << "Congratulations! You won: " << winAmt << " credits, ";
        credits += winAmt;
    }
    else {
        cout << "Better luck next time. ";
    }
    cout << credits << " Credits Left.\n";
    string output = "Do You Want To Spin Again? [y/n]: ";
    if (Input::YN(output)) {
  
        PlayRound(spinCost);
    }
    else {
        ExitGame();
    }
}

bool Slots::EnterMoney() {
    if (player->ViewCash() <= 0) {
        return false;
    }
    while (true){
        cout << "You have $" << player->ViewCash() << endl;
        cout << "How much do you want to enter into the machine: ";
        int inp;
        cin >> inp;
        if (inp <= 0 || inp > player->ViewCash()) {
            cout << "Invalid Input!";
            continue;
        }
        credits = inp;
        player->RemoveCash(inp);
        break;
    }
    return true;
    
}

void Slots::PlayGame() {
    int playAmt = 0;
    string output = "What credit level would you like to play at?\n1: 1\n2: 5\n3: 10\n4: 50\n5: 100\nEnter Your Choice: ";
    switch (Input::GetInput(output, 5)){
    case 1:
        playAmt = 1;
        break;
    case 2:
        playAmt = 5;
        break;
    case 3:
        playAmt = 10;
        break;
    case 4:
        playAmt = 50;
        break;
    case 5:
        playAmt = 100;
        break;
    default:
        break;
    }

    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    EnterMoney();
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    PlayRound(playAmt);
}




