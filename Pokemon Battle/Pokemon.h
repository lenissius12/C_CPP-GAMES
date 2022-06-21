#pragma once
#include <iostream>
#include "Moves.h"

using namespace std;

class Pokemon
{
private:
	string Name;
	string Type;
	int HP;
	int Atk;
	int Def;
	int Satk;
	int Sdef;
	int Spe;

public:
	Moves move1;
	Moves move2;
	Moves move3;
	Moves move4;
	Pokemon();
	void setName(string);
	void setType(int);
	void setHP(int);
	void setAtk(int);
	void setDef(int);
	void setSatk(int);
	void setSdef(int);
	void setSpe(int);
	string getName();
	string getType();
	int getHP();
	int getAtk();
	int getDef();
	int getSatk();
	int getSdef();
	int getSpe();

};
