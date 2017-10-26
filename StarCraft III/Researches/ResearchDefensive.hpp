//
//  ResearchDefensive.hpp
//  StarCraft III
//
//  Created by Paweł Kulig on 24.10.2017.
//  Copyright © 2017 Paweł Kulig. All rights reserved.
//

#ifndef ResearchDefensive_hpp
#define ResearchDefensive_hpp

#include <stdio.h>
#include "Research.hpp"

class ResearchDefensive: public Research
{
protected:
    int bonus;
    
public:
    ResearchDefensive();
    
    std::string getname();
    int getlvl();
    int getcost();
    int getbonus();
    
    void setname(std::string name);
    void setlvl(int lvl);
    void setcost(int cost);
    //void setadditionalHp(int additionalHp);
    //void setadditionalDefense
    
};

#endif /* ResearchDefensive_hpp */
