#ifndef unit_h
#define unit_h
#include "CSVparser.h"

class Unit
{
	string name;
	string description;
	string type;
	int attack;
	int hp;
	int maxHp;
	int cost;
	bool alive; //1 - alive; 0 - dead

	public:
		Unit(string name, string type, int attack, int maxHp);
		Unit();

		//GETTERS/SETTERS
		void setname(string name);
		string getname();
		
		void settype(string type);
		string gettype();

		void setattack(int attack);
		int getattack();

		void sethp(int hp);
		int gethp();

		void setmaxHp(int maxHp);
		int getmaxHp();

		void setcost(int cost);
		int getcost();

		void setdescription(string description);
		string getdescription();

		void setalive(bool alive);
		bool getalive();

		bool initializeFromFile(int number, string filename = "resources/defences.csv");
		/* Initializes object with data from file. 
		Number is number of line to initialize from. 
		(1 obj. - 1 line)*/

		Unit operator*(Unit u);
		/*fight between two diffrent units 
		left side strikes first but strike 
		from both sides is guaranteed*/

		Unit operator+(Unit u);
		/*fight between two diffrent units 
		left side strikes first if attacker 
		kills defender, defender does not make dmg*/		
};

#endif