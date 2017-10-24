//
//  Blasters.cpp
//  StarCraft III
//
//  Created by Paweł Kulig on 24.10.2017.
//  Copyright © 2017 Paweł Kulig. All rights reserved.
//

#include "Blasters.hpp"

Blasters::Blasters()
{
    this->name = "Blasters";
    this->cost = 100;
    this->additionalAttack = 1;
}

Blasters::Blasters(int cost)
{
    this->name = "Blasters";
    this->cost = cost;
    this->additionalAttack = 1;
}

Blasters::Blasters(int cost, int additionalAttack)
{
    this->name = "Blasters";
    this->cost = cost;
    this->additionalAttack = additionalAttack;
}
