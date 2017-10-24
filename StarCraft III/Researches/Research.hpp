//
//  Research.hpp
//  StarCraft III
//
//  Created by Paweł Kulig on 24.10.2017.
//  Copyright © 2017 Paweł Kulig. All rights reserved.
//

#ifndef Research_hpp
#define Research_hpp

#include <stdio.h>
#include <string>

class Research
{
protected:
    std::string name;
    int lvl;
    int cost;
    int nextLvlCost;
public:
    bool upgrade();
    int getNextLvlCost();
    
    virtual std::string getname()=0;
    virtual int getlvl()=0;
    virtual int getcost()=0;
    
    virtual void setname(std::string name)=0;
    virtual void setlvl(int lvl)=0;
    virtual void setcost(int cost)=0;
    
};

#endif /* Research_hpp */
