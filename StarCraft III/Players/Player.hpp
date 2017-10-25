//
//  Player.hpp
//  StarCraft III
//
//  Created by Paweł Kulig on 25.10.2017.
//  Copyright © 2017 Paweł Kulig. All rights reserved.
//

#ifndef Player_hpp
#define Player_hpp

#include <stdio.h>
#include <string>
#include <vector>
#include "UnitTerran.hpp"
#include "UnitZerg.hpp"
#include "UnitProtos.hpp"

class Player
{
protected:
    std::vector<Unit> availUnits;
    std::vector<Unit> units;
    std::string name;
    std::string race;
    
    std::vector<Unit> getavalUnits()=0;
    std::vector<Unit> getunits()=0;
    std::string getname()=0;
    std::string getrace()=0;
    
    void setavalUnits(std::vector<Unit> avalUnits)=0;
    void setunits(std::vector<Unit> units)=0;
    void setname(std::string name)=0;
    void setrace(std::string race)=0;
    
};


#endif /* Player_hpp */
