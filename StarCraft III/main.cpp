#include "libs.h"
#include "game.h"
#include "CSVparser.h"

//std::vector <Unit> Attack::availAttackers;

//units bonuses

int UnitTerran::additionalAttack = 0;
int UnitTerran::additionalHp = 0;

int UnitProtos::additionalAttack = 0;
int UnitProtos::additionalHp = 0;

int UnitZerg::additionalAttack = 0;
int UnitZerg::additionalHp = 0;

//units bonuses


int Game::difficulty = 2;

int main()
{
    Game game;
    //CSVparser p("highscores");
    //p.addHighscore("Pablo", 12);
    
    return 0;
}
