#include "player.h"


Player::Player(int startResources)
{
    setname(Ui::getPlayerName());
    Ui::clearScreen(5);
    setrace(Ui::getPlayerRace());
	setresources(startResources);
}

std::vector <Unit> Player::getunits()
{
	return units;
}

std::vector <Unit> Player::getavailUnits()
{
    return availUnits;
}

void Player::setunits(std::vector <Unit> units)
{
	this->units = units;
}

std::string Player::getrace()
{
    return this->race;
}

void Player::setrace(std::string race)
{
    this->race = race;
}

void Player::setname(std::string name)
{
	this->name = name;
}

std::string Player::getname()
{
	return name;
}

void Player::setresources(int resources)
{
	this->resources = resources;
}

int Player::getresources()
{
	return resources;
}

void Player::loadAvailUnits()
{
    int i=0;
    bool ret = true;
    Unit unit;
    if(race == "T")
    {
        UnitTerran unit;
    }
    
    if(race == "P")
    {
        UnitProtos unit;
    }
    
    if(race == "Z")
    {
        UnitZerg unit;
    }
    
    while(ret)
    {
        ret = unit.initializeFromFile(i++);
        availUnits.push_back(unit);
    }
    
}

int Player::buildUnit(Unit unit)
{
	if(unit.getcost()<resources)
	{
		units.push_back(unit);
		resources-=unit.getcost();
	}
	else
	{
        Ui::showMessage("Not enough resources to recruit: " + unit.getname());
	}

	return 0;
}
