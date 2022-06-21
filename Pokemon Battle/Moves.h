#pragma once
#include <iostream>
using namespace std;
class Moves
{
private:
	string Name;
	int Power;
public:
	Moves();
	void setName(string);
	void setPower(int);
	string getName();
	int getPower();
};

