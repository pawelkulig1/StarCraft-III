//
//  Healtkit.hpp
//  StarCraft III
//
//  Created by Paweł Kulig on 24.10.2017.
//  Copyright © 2017 Paweł Kulig. All rights reserved.
//

#ifndef Healtkit_hpp
#define Healtkit_hpp

#include <stdio.h>
#include "ResearchDefensive.hpp"

class Healthkit: public ResearchDefensive
{
public:
    Healthkit();
    
    int getCost();
};

#endif /* Healtkit_hpp */
