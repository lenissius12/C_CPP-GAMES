#ifndef GAME_H
#define GAME_H
#include <iostream>
#include <conio.h>
#include <fstream>
#include <time.h>
#include <windows.h>
#include <mmsystem.h>


using namespace std;



class game
{
private:
    bool Status;
    int Counter;

public:
    game();
    void setCounter(int&);
    int getCounter();
    void setStatus(bool&);
    bool getStatus();
    void counterDecrease();
    void Menu(game&);
    void Background(game&);
    void Settings(game&);
    void Music();
    void wordGenerator(string&);
    void Hard();
    void Normal();
    void Easy();

};

game::game()
{
    Status = true;
    Counter = 3;
}

void game::setStatus(bool& flag) {
    Status = flag;
}
bool game::getStatus() {
    return Status;
}
void game::setCounter(int& value) {
    Counter = value;
}
int game::getCounter() {
    return Counter;
}
void game::Easy() {
    Counter = 5;
}
void game::Normal() {
    Counter = 3;
}
void game::Hard() {
    Counter = 1;
}
void game::counterDecrease() {
    Counter--;
}

void game::Music() {
    PlaySound(TEXT("C:\\Users\\usuario1\\Documents\\UNIVERSIDAD\\C++\\Hanged Game\\Hanged Game\\Hanged Game\\Saw.wav"), NULL, SND_LOOP | SND_ASYNC);
}

void game::wordGenerator(string& key) {
    ifstream file;
    string wordlist[10];
    srand(time(NULL));

    file.open("C:\\Users\\usuario1\\Documents\\UNIVERSIDAD\\C++\\Hanged Game\\Hanged Game\\Hanged Game\\List.txt");
    for (int i = 0; i < 10; i++) {
        file >> wordlist[i];
    }
    int random = rand() % 10;
    key = wordlist[random];

}

void game::Menu(game& aux) {
    int op;
    char ascii92 = 92;
    aux.Music();
    do {
        system("cls");
        cout << "////////////////////////////////////////////////////////" << endl;
        cout << "///////                                          ///////" << endl;
        cout << "///////       ___                 [0]exit        ///////" << endl;
        cout << "///////     /     " << ascii92 << "               [1]Play        ///////" << endl;
        cout << "///////    |       |              [2]Settings    ///////" << endl;
        cout << "///////     " << ascii92 << " ___ /                              ///////" << endl;
        cout << "///////        |                                 ///////" << endl;
        cout << "///////   -----|-----                            ///////" << endl;
        cout << "///////        |                                 ///////" << endl;
        cout << "///////       / " << ascii92 << "                                ///////" << endl;
        cout << "///////      /   " << ascii92 << "                               ///////" << endl;
        cout << "////////////////////////////////////////////////////////" << endl << endl << endl;


        cout << "Selecciona una opcion: "; cin >> op;
        switch (op) {
        case 0:
            exit(-1);
        case 1:
            aux.Background(aux);
            break;
        case 2:
            aux.Settings(aux);
            break;
        default:
            cout << "Invalid Option!" << endl;

        }

    } while (op != 0);
}


void game::Settings(game& aux) {
    int Settings_Op;
    int Difficulty_Op;
    do {
        system("cls");
        cout << ">>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>" << endl;
        cout << ">>>>>>>>>>>>>>>>>>>>>> [1]Difficulty    >>" << endl;
        cout << ">>>>>>>>>>>>>>>>>>>>>>>>>> [2]Music     >>" << endl;
        cout << ">>>>>>>>>>>>>>>>>>>>>>>>>>>>> [3]Exit   >>" << endl;
        cout << ">>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>" << endl << endl;

        cout << "Select An Option: "; cin >> Settings_Op;
        switch (Settings_Op) {
        case 1:
            do {
                system("cls");
                cout << "[1]Hard      [2]Normal    [3]Easy   [4]Exit" << endl << endl;
                cout << "Key an option: "; cin >> Difficulty_Op;
                switch (Difficulty_Op) {
                case 1:
                    aux.Hard();
                    cout << "\n\nYou have chosen Hard Difficulty" << endl;
                    _getch();
                    break;
                case 2:
                    aux.Normal();
                    cout << "\n\nYou have chosen Normal Difficulty" << endl;
                    _getch();
                    break;
                case 3:
                    aux.Easy();
                    cout << "\n\nYou have chosen Easy Difficulty" << endl;
                    _getch();
                    break;
                case 4:
                    break;
                default:
                    cout << "Select a valid option" << endl;
                    _getch();
                    break;
                }
            } while (Difficulty_Op != 4);

        case 2:
            break;
        case 3:
            break;
        default:
            cout << "Select a valid option" << endl;
        }
    } while (Settings_Op != 3);
}


void game::Background(game& aux) {
    char ascii92 = 92;
    char Play_Op;
    char repeatedWord;
    string keyword;
    aux.wordGenerator(keyword);
    string mysteryWord(keyword.length(), '*');

    do {
        bool guess = false;
        bool repeated = false;
        system("cls");
        if (aux.getCounter() == 5) {
            cout << " ________" << endl;
            cout << " |      |                    " << endl;
            cout << " |      O                    " << endl;
            cout << " |    --|--                  " << endl;
            cout << " |     / " << ascii92 << "                " << endl << endl;
        }
        else if (aux.getCounter() == 4) {
            cout << "       O                    " << endl;
            cout << "     --|                    " << endl;
            cout << "      / " << ascii92 << "                " << endl << endl;
        }
        else if (aux.getCounter() == 3) {
            cout << "       O                    " << endl;
            cout << "       |                  " << endl;
            cout << "      / " << ascii92 << "                " << endl << endl;
        }
        else if (aux.getCounter() == 2) {
            cout << "       O                    " << endl;
            cout << "       |                  " << endl;
            cout << "      /                 " << endl << endl;
        }
        else if (aux.getCounter() == 1) {
            cout << "       O                    " << endl;
            cout << "       |                     " << endl;
            cout << "                            " << endl << endl;
        }
        else if (aux.getCounter() == 0) {
            cout << "       O                    " << endl;
            cout << "                             " << endl;
            cout << "                            " << endl << endl;
        }

        cout << "\nNumber of opportunities: " << aux.getCounter() << endl;
        cout << mysteryWord << endl;
        cout << "Guess a letter of the Mystery Word: "; cin >> Play_Op;

        for (int i = 0; i < mysteryWord.length(); i++) {
            if (keyword[i] == Play_Op) {
                if (Play_Op == mysteryWord[i]) {
                    cout << Play_Op << ": Is Already in the word" << endl;
                    aux.counterDecrease();
                    repeated = true;
                    _getch();
                    break;
                }
                else {
                    mysteryWord[i] = Play_Op;
                    guess = true;
                }
            }
        }
        if (repeated) {
            continue;
        }

        if (guess == false) {
            cout << "Wrong guess!" << endl;
            aux.counterDecrease();
            _getch();
        }

        if (keyword == mysteryWord) {
            cout << "You Won!!! Congratulations" << endl;
            aux.Normal();
            _getch();
            return aux.Menu(aux);
        }


    } while (aux.getCounter() != 0);

    if (aux.getCounter() <= 0) {
        aux.Normal();
        cout << "You lose :(" << endl;
        _getch();
    }
}




#endif
