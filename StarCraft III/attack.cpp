#include "attack.h"

Attack::Attack(int day)
{
	this->day = day;
	checkIfAttack();

	if(attackThisRound)
	{
		loadPossibleAttackers();
		createUnitsToAttack();
		//battle();
	}
}

void Attack::setday(int day)
{
	this->day = day;
}

int Attack::getday()
{
	return day;
}

bool Attack::getattackThisRound()
{
	return attackThisRound;
}

void Attack::setattackThisRound(bool attackThisRound)
{
	this->attackThisRound = attackThisRound;
}

void Attack::loadPossibleAttackers()
{
	Unit unit;
	for(int i=0;i<3;i++)
	{

		unit.initializeFromFile(i+1, "resources/attacker.csv");
		availAttackers.push_back(unit);
		//cout<<attacker.ge
	}
}

void Attack::createUnitsToAttack()
{
	//depends on day
	srand(time(NULL));
	for(int i=0;i<day;i++)
	{
		if(day<3)
		{
			attacker.push_back(availAttackers[0]);
		}
		else
		{
			attacker.push_back(availAttackers[rand()%availAttackers.size()]);
		}

	}
}

bool Attack::battle(vector <Unit> *defender)
{

	if(attacker.size()>0)
		cout<<"Attacking units:"<<endl<<endl;

	for(int i=0;i<attacker.size();i++)
	{
		cout<<attacker.at(i).getname()<<endl;
	}

	cout<<endl<<endl;
	if(attacker.size()>0)
		cout<<"Defending units:"<<endl<<endl;

	for(int i=0;i<defender->size();i++)
	{
		cout<<defender->at(i).getname()<<endl;
	}

	cout<<endl<<endl;
	

	//simulateBattle
	srand(time(NULL));
	while(true)
	{
		//delete all units with alive==0
		for(int i=0;i<attacker.size();i++)
		{
			if(attacker.at(i).getalive() == 0)
			{
				//cout<<"deleting attacker!"<<endl;
				attacker.erase(attacker.begin()+i);
				i=0;
			}
		}

		for(int i=0;i<defender->size();i++)
		{
			if(defender->at(i).getalive() == 0)
			{
				//cout<<"deleting defender!"<<endl;
				defender->erase(defender->begin()+i);
				i=0;
			}
		}
		//check if both sides have alive units

		if(attacker.size() == 0)
		{
			return 1;
		}

		if(defender->size() == 0)
		{
			return 0;
		}

		//simulate fight 

		int rnd1 = 0;
		int rnd2 = 0;

		rnd1 = round(rand()%(defender->size()));
		rnd2 = round(rand()%(attacker.size()));
		defender->at(rnd1) = attacker.at(rnd2)*defender->at(rnd1);


		// }
	}
}

void Attack::checkIfAttack()
{
	srand(time(NULL));
	int rnd = (rand()%10)+1;

	if(day>rnd)
	{
		attackThisRound = 1;
	}
	else
	{
		attackThisRound = 0;
	}
}