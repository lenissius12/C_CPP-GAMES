#pragma once
#include <iostream>
#include "Pokemon.h"
#include <math.h>
class Field
{
private:
	Pokemon* poke1;
	Pokemon* poke2;

public:
	Field() {
		poke1 = NULL;
		poke2 = NULL;
	}
	void setFighters(Pokemon*, Pokemon*);
	void printMenu();
	int speedMatch();
	bool PokemonKO(Pokemon);
	bool victoryCondition();
	void playerInput(int*);
	void takeFoeTurn(int*);
	void updatePlayer(int);
	void updateFoe(int);
	void updateHUD(int, int, int*, int*, int);
	void update(int*, int*);
	void takePlayerTurn(int);
	void printHUD(int, int);
	void start();

};
