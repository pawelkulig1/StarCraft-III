//
//  ResearchOffensive.hpp
//  StarCraft III
//
//  Created by Paweł Kulig on 24.10.2017.
//  Copyright © 2017 Paweł Kulig. All rights reserved.
//

#ifndef ResearchOffensive_hpp
#define ResearchOffensive_hpp

#include <stdio.h>
#include "Research.hpp"

class ResearchOffensive: public Research
{
protected:
    int bonus;
public:
    ResearchOffensive();
    std::string getname();
    int getlvl();
    int getcost();
    int getbonus();
    
    void setname(std::string name);
    void setlvl(int lvl);
    void setcost(int cost);
    void setadditionalAttack(int additionalAttack);
};

#endif /* ResearchOffensive_hpp */
