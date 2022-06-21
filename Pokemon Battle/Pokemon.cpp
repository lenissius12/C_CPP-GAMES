#include "Pokemon.h"
#include <iostream>
using namespace std;

Pokemon::Pokemon() {
	Name = "";
	Type = "";
	HP = 0;
	Atk = 0;
	Def = 0;
	Satk = 0;
	Sdef = 0;
	Spe = 0;
}

void Pokemon::setName(string _Name) {
	Name = _Name;
}
void Pokemon::setType(int value) {
	switch (value) {
	case 1:
		Type = "Grass";
		break;
	case 2:
		Type = "Water";
		break;
	case 3:
		Type = "Fire";
		break;
	case 4:
		Type = "Normal";
		break;
	case 5:
		Type = "Fighting";
		break;
	case 6:
		Type = "Electric";
		break;
	case 7:
		Type = "Ground";
		break;
	case 8:
		Type = "Rock";
		break;
	case 9:
		Type = "Flying";
		break;
	case 10:
		Type = "Psychic";
		break;
	case 11:
		Type = "Ghost";
		break;
	case 12:
		Type = "Bug";
		break;
	case 13:
		Type = "Poison";
		break;
	case 14:
		Type = "Dragon";
		break;
	case 15:
		Type = "Dark";
		break;
	case 16:
		Type = "Steel";
		break;
	case 17:
		Type = "Fairy";
		break;
	default:
		Type = "Unknown";
		break;
	}
}
void Pokemon::setHP(int _HP) {
	HP = _HP;
}
void Pokemon::setAtk(int _Atk) {
	Atk = _Atk;
}
void Pokemon::setDef(int _Def) {
	Def = _Def;
}
void Pokemon::setSatk(int _Satk) {
	Satk = _Satk;
}
void Pokemon::setSdef(int _Sdef) {
	Sdef = _Sdef;
}
void Pokemon::setSpe(int _Spe) {
	Spe = _Spe;
}
string Pokemon::getName() {
	return Name;
}
string Pokemon::getType() {
	return Type;
}
int Pokemon::getHP() {
	return HP;
}
int Pokemon::getAtk() {
	return Atk;
}
int Pokemon::getDef() {
	return Def;
}
int Pokemon::getSatk() {
	return Satk;
}
int Pokemon::getSdef() {
	return Sdef;
}
int Pokemon::getSpe() {
	return Spe;
}