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


