#ifndef attack_h
#define attack_h

#include "libs.h"
#include "Units/unit.h"
#include "game.h"
#include "player.h"

class Attack
{
	int day;
	bool attackThisRound;
	std::vector <Unit> attacker;
    static std::vector <Unit> availAttackers;
    static std::string attackerRace;
public:
    
	//constructors
	Attack(int day);
	
	//setters/getters
	void setday(int day);
	int getday();
	bool getattackThisRound();
	void setattackThisRound(bool attackThisRound);

    static void loadPossibleAttackers();

	//methods
	void checkIfAttack();
	void createUnitsToAttack();
	bool battle(Player *player);
    static std::string choseEnemyRace();
	//1 - defenders win; 0 - attacker wins
};

//std::vector <Unit> Attack::availAttackers;
#endif
