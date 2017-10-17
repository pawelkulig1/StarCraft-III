#ifndef player_h
#define player_h

#include "libs.h"
#include "ui.h"
#include "unit.h"


#include <unistd.h> //sleep()

class Player
{
    std::vector <Unit> defenceUnits;
	//Ui ui;
	std::string name;
	int resources;
	public:
		Player(int startResources=30);
		std::vector <Unit> getdefenceUnits();
		void setdefenceUnits(std::vector <Unit> defenceUnits);
		void setname(std::string name);
		std::string getname();
		void setresources(int resources);
		int getresources();
		int buildDefence(Unit building);

};

#endif
