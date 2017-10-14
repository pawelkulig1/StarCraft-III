#ifndef player_h
#define player_h

#include "libs.h"
#include "ui.h"
#include "unit.h"


#include <unistd.h> //sleep()

class Player
{
    vector <Unit> defenceUnits;
	Ui ui;
	string name;
	int resources;
	public:
		Player(int startResources=30);
		vector <Unit> getdefenceUnits();
		void setdefenceUnits(vector <Unit> defenceUnits);
		void setname(string name);
		string getname();
		void setresources(int resources);
		int getresources();
		int buildDefence(Unit building);

};

#endif
