//
//  Research.cpp
//  StarCraft III
//
//  Created by Paweł Kulig on 24.10.2017.
//  Copyright © 2017 Paweł Kulig. All rights reserved.
//

#include "Research.hpp"

bool Research::upgrade()
{
    this->lvl += 1;
    return 1;
}

int Research::getNextLvlCost()
{
    return this->cost + (this->lvl * this->nextLvlCost);
}


