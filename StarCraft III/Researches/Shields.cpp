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
    this->cost = 300;
    this->bonus = 2;
}

Shields::Shields(int cost)
{
    this->name = "Shields";
    this->cost = cost;
    this->bonus = 2;
}

Shields::Shields(int cost, int bonus)
{
    this->name = "Shields";
    this->cost = cost;
    this->bonus = bonus;
}

