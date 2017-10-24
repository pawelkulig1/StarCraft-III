//
//  UnitProtos.hpp
//  StarCraft III
//
//  Created by Paweł Kulig on 24.10.2017.
//  Copyright © 2017 Paweł Kulig. All rights reserved.
//

#ifndef UnitProtos_hpp
#define UnitProtos_hpp

#include <stdio.h>
#include "unit.h"

class UnitProtos: public Unit
{
    
public:
    UnitProtos();
    static int additionalAttack;
    static int additionalHp;
    std::string filepath; //path to file to get availUnits;
};

#endif /* UnitProtos_hpp */
