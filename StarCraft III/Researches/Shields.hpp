//
//  Shields.hpp
//  StarCraft III
//
//  Created by Paweł Kulig on 24.10.2017.
//  Copyright © 2017 Paweł Kulig. All rights reserved.
//

#ifndef Shields_hpp
#define Shields_hpp

#include <stdio.h>
#include "ResearchDefensive.hpp"

class Shields: public ResearchDefensive
{
public:
    Shields();
    Shields(int cost);
    Shields(int cost, int additionalDefensePerLvl);
};

#endif /* Shields_hpp */

