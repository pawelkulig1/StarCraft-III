//
//  ResearchOffensive.cpp
//  StarCraft III
//
//  Created by Paweł Kulig on 24.10.2017.
//  Copyright © 2017 Paweł Kulig. All rights reserved.
//

#include "ResearchOffensive.hpp"

ResearchOffensive::ResearchOffensive()
{
    this->lvl = 0;
}

std::string ResearchOffensive::getname()
{
    return this->name;
}

int ResearchOffensive::getcost()
{
    return this->cost;
}

int ResearchOffensive::getlvl()
{
    return this->lvl;
}

int ResearchOffensive::getadditionalAttack()
{
    return this->additionalAttack;
}

void ResearchOffensive::setname(std::string name)
{
    this->name = name;
}

void ResearchOffensive::setlvl(int lvl)
{
    this->lvl = lvl;
}

void ResearchOffensive::setcost(int cost)
{
    this->cost = cost;
}

