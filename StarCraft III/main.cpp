#include "libs.h"
#include "game.h"
#include "Blasters.hpp"

std::vector <Unit> Attack::availAttackers;

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
    return 0;
    

//    UnitTerran unit;
//    std::cout<<unit.getfilepath()<<std::endl;
//    std::cout<<unit.initializeFromFile(1)<<std::endl;
//    std::cout<<unit.getname()<<std::endl;
//
    
    /*Player player;
    std::cout<<player.getname()<<" - "<<player.getrace()<<std::endl;

    player.loadAvailUnits();*/
    //player.getavailUnits();
    
    
}
