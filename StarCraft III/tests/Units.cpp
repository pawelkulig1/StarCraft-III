//
//  Units.cpp
//  StarCraft III
//
//  Created by Paweł Kulig on 24.10.2017.
//  Copyright © 2017 Paweł Kulig. All rights reserved.
//

#include <stdio.h>
#include <iostream>
#include "UnitZerg.hpp"


int main()
{
    UnitZerg zerg;
    zerg.initializeFromFile(2);
    std::cout<<zerg.getattack()<<std::endl;
}
