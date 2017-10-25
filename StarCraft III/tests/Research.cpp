//
//  Research.cpp
//  StarCraft III
//
//  Created by Paweł Kulig on 24.10.2017.
//  Copyright © 2017 Paweł Kulig. All rights reserved.
//

#include <stdio.h>
#include "Blasters.hpp"
#include "Shields.hpp"
#include <iostream>
#include <vector>

int main()
{
    //std::cout<<"test"<<std::endl;
    std::vector <ResearchOffensive> temp;
    Blasters blasterTechnology;
    
    temp.push_back(blasterTechnology);
    
    std::cout<<blasterTechnology.getlvl()<<std::endl;
    blasterTechnology.upgrade();
    std::cout<<blasterTechnology.getlvl()<<std::endl;
    std::cout<<blasterTechnology.getadditionalAttack();
    
    Shields shieldTechnology;
    shieldTechnology.getlvl();
    shieldTechnology.upgrade();
    
}
