//
//  UnitZerg.hpp
//  StarCraft III
//
//  Created by Paweł Kulig on 24.10.2017.
//  Copyright © 2017 Paweł Kulig. All rights reserved.
//

#ifndef UnitZerg_hpp
#define UnitZerg_hpp

#include <stdio.h>
#include "unit.h"

class UnitZerg : public Unit
{
public:
    UnitZerg();
    static int additionalAttack;
    static int additionalHp;
    //std::string filepath;
    
};


#endif /* UnitZerg_hpp */
