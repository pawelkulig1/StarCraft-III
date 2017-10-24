//
//  Blasters.hpp
//  StarCraft III
//
//  Created by Paweł Kulig on 24.10.2017.
//  Copyright © 2017 Paweł Kulig. All rights reserved.
//

#ifndef Blasters_hpp
#define Blasters_hpp

#include <stdio.h>
#include "ResearchOffensive.hpp"

class Blasters: public ResearchOffensive
{
public:
    Blasters();
    Blasters(int cost);
    Blasters(int cost, int additionalAttack);
    
    
};

#endif /* Blasters_hpp */
