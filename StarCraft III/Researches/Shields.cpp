//
//  Shields.cpp
//  StarCraft III
//
//  Created by Paweł Kulig on 24.10.2017.
//  Copyright © 2017 Paweł Kulig. All rights reserved.
//

#include "Shields.hpp"

Shields::Shields()
{
    this->name = "Shields";
    this->cost = 100;
    this->additionalDefense = 1;
}

Shields::Shields(int cost)
{
    this->name = "Shields";
    this->cost = cost;
    this->additionalDefense = 1;
}

Shields::Shields(int cost, int additionalDefense)
{
    this->name = "Shields";
    this->cost = cost;
    this->nextLvlCost = nextLvlCost;
    this->additionalDefense = additionalDefense;
}

