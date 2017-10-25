//
//  Player.cpp
//  StarCraft III
//
//  Created by Paweł Kulig on 25.10.2017.
//  Copyright © 2017 Paweł Kulig. All rights reserved.
//

#include "Player.hpp"

std::vector<Unit> Player::getavalUnits()
{
    return availUnits;
}

std::vector<Unit> Player::getunits()
{
    return units;
}

std::string Player::getname()
{
    return name;
}

std::string Player::getrace()
{
    return race;
}

void Player::setavalUnits(std::vector<Unit> avalUnits)
{
    this->availUnits = avalUnits;
}

void Player::setunits(std::vector<Unit> units)
{
    this->units = units;
}

void Player::setname(std::string name)
{
    this->name = name;
}

void Player::setrace(std::string race)
{
    this->race = race;
}

void Player::loadAvailUnits()
{
    //std::cout<<"loading avail units"<<std::endl;
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
