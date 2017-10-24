#include "libs.h"
#include "game.h"

std::vector <Unit> Attack::availAttackers;
//unit Terran
int UnitTerran::additionalAttack = 0;
int UnitTerran::additionalHp = 0;
std::string UnitTerran::filepath = "Terran.csv";

int UnitProtos::additionalAttack = 0;
int UnitProtos::additionalHp = 0;
std::string UnitProtos::filepath = "Protos.csv";

int UnitZerg::additionalAttack = 0;
int UnitZerg::additionalHp = 0;
std::string UnitZerg::filepath = "Zerg.csv";



//unit Terran


int Game::difficulty = 2;



int main()
{
	Game game;
	return 0;
}
