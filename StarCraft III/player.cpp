#include "player.h"


Player::Player(int startResources)
{
    setname(Ui::getPlayerName());
    Ui::clearScreen(5);
    setrace(Ui::getPlayerRace());
	setresources(startResources);
    loadAvailUnits();
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
    std::cout<<"loading avail units"<<std::endl;
    int i=1;
    bool ret = true;
    //Unit unit;
    if(race == "T")
    {
        UnitTerran unit;
        while(true)
        {
            ret = unit.initializeFromFile(i++);
            if(ret == 0)
                break;
            availUnits.push_back(unit);
        }
    }
    
    if(race == "P")
    {
        UnitProtos unit;
        while(true)
        {
            ret = unit.initializeFromFile(i++);
            if(ret == 0)
                break;
            availUnits.push_back(unit);
            //std::cout<<availUnits[i].getname()<<std::endl;
        }
    }
    
    if(race == "Z")
    {
        UnitZerg unit;
        while(true)
        {
            ret = unit.initializeFromFile(i++);
            if(ret == 0)
                break;
            availUnits.push_back(unit);
            //std::cout<<availUnits[i].getname()<<std::endl;
        }
    }
}

int Player::buildUnit(int unitNumber)
{
    if(unitNumber > availUnits.size() || unitNumber < 0)
        return -1;
	if(availUnits[unitNumber].getcost()<resources)
	{
		units.push_back(availUnits[unitNumber]);
		resources-=availUnits[unitNumber].getcost();
	}
	else
	{
        Ui::showMessage("Not enough resources to recruit: " + availUnits[unitNumber].getname());
	}

	return 0;
}
