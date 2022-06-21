#include "Moves.h"
#include <iostream>
using namespace std;

Moves::Moves() {
	Name = "";
	Power = 0;
}

void Moves::setName(string _Name) {
	Name = _Name;
}
void Moves::setPower(int _Power) {
	Power = _Power;
}
string Moves::getName() {
	return Name;
}
int Moves::getPower() {
	return Power;
}