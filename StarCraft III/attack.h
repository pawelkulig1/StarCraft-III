#ifndef attack_h
#define attack_h

#include "libs.h"
#include "unit.h"
#include "game.h"

class Attack
{
	int day;
	bool attackThisRound;
	std::vector <Unit> attacker;
    static std::vector <Unit> availAttackers;
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
	bool battle(std::vector <Unit> *defender);
	//1 - defenders win; 0 - attacker wins
};

//std::vector <Unit> Attack::availAttackers;
#endif
