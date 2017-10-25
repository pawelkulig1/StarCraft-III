#ifndef player_h
#define player_h

#include "libs.h"
#include "ui.h"
#include "UnitTerran.hpp"
#include "UnitProtos.hpp"
#include "UnitZerg.hpp"


#include <unistd.h> //sleep()

class Player
{
    std::vector <Unit> units;
	//Ui ui;
	std::string name;
    std::string race; // T, P, Z - Terran, Protos, Zerg
	int resources;
    std::vector <Unit> availUnits;
    
public:
    Player(int startResources=30);
    std::vector <Unit> getunits();
    std::vector <Unit> getavailUnits();
    
    void setunits(std::vector <Unit> units);
    
    std::string getrace();
    void setrace(std::string race);
    
    void setname(std::string name);
    std::string getname();
    void setresources(int resources);
    int getresources();
    
    void loadAvailUnits();
    int buildUnit(Unit building);

};

#endif
