//
//  ResearchDefensive.cpp
//  StarCraft III
//
//  Created by Paweł Kulig on 24.10.2017.
//  Copyright © 2017 Paweł Kulig. All rights reserved.
//

#include "ResearchDefensive.hpp"

ResearchDefensive::ResearchDefensive()
{
    this->lvl = 0;
}

std::string ResearchDefensive::getname()
{
    return this->name;
}

int ResearchDefensive::getcost()
{
    return this->cost;
}

int ResearchDefensive::getlvl()
{
    return this->lvl;
}

int ResearchDefensive::getbonus()
{
    return bonus;
}

void ResearchDefensive::setname(std::string name)
{
    this->name = name;
}

void ResearchDefensive::setlvl(int lvl)
{
    this->lvl = lvl;
}

void ResearchDefensive::setcost(int cost)
{
    this->cost = cost;
}

