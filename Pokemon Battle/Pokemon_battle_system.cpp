#include <iostream>
#include "Field.h"
#include <Windows.h>
#include <mmsystem.h>

using namespace std;

int main() {
	Pokemon Pikachu;
	Pokemon Charizard;
	Field field;
	Pikachu.setHP(60);
	Pikachu.setName("Pikachu");
	Pikachu.setSpe(90);
	Pikachu.move1.setName("Thunderbolt");
	Pikachu.move1.setPower(60);
	Pikachu.move2.setName("Thunder");
	Pikachu.move2.setPower(120);

	Charizard.setHP(120);
	Charizard.setName("Charizard");
	Charizard.setSpe(100);
	Charizard.move1.setName("scratch");
	Charizard.move1.setPower(20);
	Charizard.move2.setName("Ember");
	Charizard.move2.setPower(30);


	field.setFighters(&Pikachu, &Charizard);
	field.start();


	return 0;
}