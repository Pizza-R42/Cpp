#pragma once
#include <string>
using namespace std;
class Input {
public:
	Input();
	static int GetInput(string output, int choices);
	static bool YN(string output);
};