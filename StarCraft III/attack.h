#ifndef attack_h
#define attack_h

#include "libs.h"
#include "unit.h"

class Attack
{
	int day;
	bool attackThisRound;
	vector <Unit> availAttackers;
	vector <Unit> attacker;

public:
	//constructors
	Attack(int day);
	
	//setters/getters
	void setday(int day);
	int getday();
	bool getattackThisRound();
	void setattackThisRound(bool attackThisRound);

	void loadPossibleAttackers();

	//methods
	void checkIfAttack();
	void createUnitsToAttack();
	bool battle(vector <Unit> *defender);
	//1 - defenders win; 0 - attacker wins
};

#endif