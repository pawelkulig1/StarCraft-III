//
//  Units.cpp
//  StarCraft III
//
//  Created by Paweł Kulig on 24.10.2017.
//  Copyright © 2017 Paweł Kulig. All rights reserved.
//

#include <stdio.h>
#include <iostream>
#include <vector>
#include "UnitZerg.hpp"
#include "UnitProtos.hpp"
//#include "Units/unit.h"


int UnitZerg::additionalHp = 1;
int UnitZerg::additionalAttack = 1;


int main()
{
    std::vector <Unit> unit;
    UnitZerg zerg;
    //zerg.initializeFromFile(1);
    unit.push_back(zerg);
    //temp.push_back(zerg);
    //temp.push_back(zerg);
    //temp.push_back(zerg);
    /*UnitProtos protos;
    temp.push_back(protos);
    temp.push_back(protos);
    temp.push_back(protos);*/
    
    
    //zerg.initializeFromFile(2);
    //std::cout<<zerg.getattack()<<std::endl;
    
}
