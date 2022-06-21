#include "Field.h"
#include <iostream>
#include <conio.h>
#include <time.h>
#include <Windows.h>



// HP = floor(0.01 x (2 x base + IV + floor(0.25 x EV))x level) + level + 10
//Other Stats = (floor(0.01 x (2 x base + IV + floor (0.25 x EV))x level) + 5) x nature



void Field::setFighters(Pokemon* _poke1, Pokemon* _poke2) {
    this->poke1 = *&_poke1;
    this->poke2 = *&_poke2;
}

int Field::speedMatch() {
    if (poke1->getSpe() > poke2->getSpe())
        return 0;
    else if (poke1->getSpe() < poke2->getSpe())
        return 1;
    else if (poke1->getSpe() == poke2->getSpe())
        return 2;

}

bool Field::PokemonKO(Pokemon poke) {
    if (poke.getHP() <= 0) {
        cout << poke.getName() << " se ha debilitado" << endl;
        _getch();
        return true;
    }
}

bool Field::victoryCondition() {
    if (poke1->getHP() <= 0)
        return true;
    else if (poke2->getHP() <= 0)
        return true;
    else
        return false;
}

void Field::updatePlayer(int op) {
    switch (op) {
    case 0:
        poke1->setHP(poke1->getHP() - poke2->move1.getPower());
        break;
    case 1:
        poke1->setHP(poke1->getHP() - poke2->move2.getPower());
        break;
    case 2:
        poke1->setHP(poke1->getHP() - poke2->move3.getPower());
        break;
    case 3:
        poke1->setHP(poke1->getHP() - poke2->move4.getPower());
        break;
    }
}

void Field::updateFoe(int op) {
    switch (op) {
    case 1:
        poke2->setHP(poke2->getHP() - poke1->move1.getPower());
        break;
    case 2:
        poke2->setHP(poke2->getHP() - poke1->move2.getPower());
        break;
    case 3:
        poke2->setHP(poke2->getHP() - poke1->move3.getPower());
        break;
    case 4:
        poke2->setHP(poke2->getHP() - poke1->move4.getPower());
        break;
    }
}

void Field::takeFoeTurn(int* op) {
    srand(time(NULL));
    *op = 1;
    switch (*op) {
    case 0:
        cout << poke2->getName() << " ha usado " << poke2->move1.getName() << endl;
        break;
    case 1:
        cout << poke2->getName() << " ha usado " << poke2->move2.getName() << endl;
        break;

    case 2:
        cout << poke2->getName() << " ha usado " << poke2->move3.getName() << endl;
        break;

    case 3:
        cout << poke2->getName() << " ha usado " << poke2->move4.getName() << endl;
        break;
    }
}


void Field::updateHUD(int op1, int op2, int* maxHP1, int* maxHP2, int option) {
    switch (option) {
        //Player faster than foe(First part)
    case 0:
        updateFoe(op1);
        Sleep(1000);
        system("cls");
        printHUD(*maxHP1, *maxHP2);
        break;
    case 1:
        //Player faster than foe(Second part)
        updatePlayer(op2);
        Sleep(1000);
        system("cls");
        printHUD(*maxHP1, *maxHP2);
        break;

    case 2:
        //Foe faster than player(First part)
        updatePlayer(op2);
        Sleep(1000);
        system("cls");
        printHUD(*maxHP1, *maxHP2);
        break;
    case 3:
        //For faster than player(Second Part)
        updateFoe(op1);
        Sleep(1000);
        system("cls");
        printHUD(*maxHP1, *maxHP2);
        break;

    }
}

void Field::update(int* maxHP1, int* maxHP2) {
    int op = -1, op2 = -1, option;
    speedMatch();
    if (speedMatch() == 0) {
        option = 0;
        takePlayerTurn(op);
        updateHUD(op, op2, *&maxHP1, *&maxHP2, option);
        if (PokemonKO(*poke2) == true) {
            exit(-1);
        }
        option = 1;
        takeFoeTurn(&op2);
        updateHUD(op, op2, *&maxHP1, *&maxHP2, option);
        if (PokemonKO(*poke1) == true) {
            exit(-1);
        }
    }
    else if (speedMatch() == 1) {
        option = 2;
        playerInput(&op);
        takeFoeTurn(&op2);
        updateHUD(op, op2, *&maxHP1, *&maxHP2, option);
        if (PokemonKO(*poke1) == true)
            exit(-1);
        option = 3;
        takePlayerTurn(op);
        updateHUD(op, op2, *&maxHP1, *&maxHP2, option);
        if (PokemonKO(*poke2) == true)
            exit(-1);
    }
    else {
        srand(time(NULL));
        int turn = rand() % 2;
        if (turn == 0) {
            takePlayerTurn(op);
            takeFoeTurn(&op);
        }
        else {
            takeFoeTurn(&op);
            takePlayerTurn(op);
        }
    }
    _getch();
}

void Field::playerInput(int* op) {
    cout << "Que vas hacer: ";
    cin >> *op;

}

void Field::takePlayerTurn(int op) {
    switch (op) {
    case 1:
        cout << poke1->getName() << " ha usado " << poke1->move1.getName() << endl;
        break;

    case 2:
        cout << poke1->getName() << " ha usado " << poke1->move2.getName() << endl;
        break;

    case 3:
        cout << poke1->getName() << " ha usado " << poke1->move3.getName() << endl;
        break;

    case 4:
        cout << poke1->getName() << " ha usado " << poke1->move4.getName() << endl;
        break;
    }
}


void Field::printMenu() {
    cout << "[1]" << poke1->move1.getName() << endl;
    cout << "[2]" << poke1->move2.getName() << endl;
    cout << "[3]" << poke1->move3.getName() << endl;
    cout << "[4]" << poke1->move4.getName() << endl;
    cout << "Selecciona un movimiento" << endl;
}

void Field::printHUD(int maxHP1, int maxHP2) {
    cout << poke1->getName() << endl;
    cout << "HP " << poke1->getHP() << "/" << maxHP1 << endl;
    cout << "\t\t\t" << poke2->getName() << endl;
    cout << "\t\t\t" << "HP " << poke2->getHP() << "/" << maxHP2 << endl;
    cout << endl << endl;

    printMenu();
}

void Field::start() {
    int maxHP1 = poke1->getHP();
    int maxHP2 = poke2->getHP();
    do {
        system("cls");
        printHUD(maxHP1, maxHP2);
        update(&maxHP1, &maxHP2);


    } while (!victoryCondition());
}
