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
    
    
    /*Player player;
    std::cout<<player.getname()<<" - "<<player.getrace()<<std::endl;
    
    
    Blasters blasterTechnology;
    std::cout<<blasterTechnology.getlvl()<<std::endl;
    std::cout<<blasterTechnology.getadditionalAttack()<<std::endl;*/
    
    
}
