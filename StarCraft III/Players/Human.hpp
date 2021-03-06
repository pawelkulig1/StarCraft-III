//
//  Human.hpp
//  StarCraft III
//
//  Created by Paweł Kulig on 25.10.2017.
//  Copyright © 2017 Paweł Kulig. All rights reserved.
//

#ifndef Human_hpp
#define Human_hpp

#include <stdio.h>
#include "Player.hpp"
#include "ui.h"

class Human: public Player
{
    int resources;
    int additionalAttack;
    int additionalHp;
public:
    Human(int startResources=30);
    void setresources(int resources);
    int getresources();
    
    void setadditionalAttack(int additionalAttack);
    int getadditionalAttack();
    
    void setadditionalHp(int additionalHp);
    int getadditionalHp();
    int buildUnit(int unitNumber);
    
};

#endif /* Human_hpp */
