//
//  UnitTerran.hpp
//  StarCraft III
//
//  Created by Paweł Kulig on 24.10.2017.
//  Copyright © 2017 Paweł Kulig. All rights reserved.
//

#ifndef UnitTerran_hpp
#define UnitTerran_hpp

#include <stdio.h>
#include "unit.h"

class UnitTerran : public Unit
{
    
public:
    UnitTerran();
    static int additionalAttack;
    static int additionalHp;
    //std::string filepath; //path to file to get availUnits;
};

#endif /* UnitTerran_hpp */
