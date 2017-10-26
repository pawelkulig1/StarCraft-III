//
//  Human.cpp
//  StarCraft III
//
//  Created by Paweł Kulig on 25.10.2017.
//  Copyright © 2017 Paweł Kulig. All rights reserved.
//

#include "Human.hpp"

Human::Human(int startResources)
{
    setname(Ui::getPlayerName());
    Ui::clearScreen(5);
    setrace(Ui::getPlayerRace());
    setresources(startResources);
    loadAvailUnits();
}

void Human::setresources(int resources)
{
    this->resources = resources;
}

int Human::getresources()
{
    return resources;
}

void Human::setadditionalAttack(int additionalAttack)
{
    this->additionalAttack = additionalAttack;
    for(int i=0;i<units.size();i++)
    {
        units[i].setattack(units[i].getattack()+this->additionalAttack);
    }
    for(int i=0;i<availUnits.size();i++)
    {
        availUnits[i].setattack(availUnits[i].getattack()+this->additionalAttack);
    }
}
int Human::getadditionalAttack()
{
    return additionalAttack;
}

void Human::setadditionalHp(int additionalHp)
{
    this->additionalHp = additionalHp;
    for(int i=0;i<units.size();i++)
    {
        units[i].sethp(units[i].gethp()+this->additionalHp);
    }
    for(int i=0;i<availUnits.size();i++)
    {
        availUnits[i].sethp(availUnits[i].gethp()+this->additionalHp);
    }
}

int Human::getadditionalHp()
{
    return additionalHp;
}

int Human::buildUnit(int unitNumber)
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


