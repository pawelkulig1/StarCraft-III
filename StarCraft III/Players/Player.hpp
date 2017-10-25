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
public:
    std::vector<Unit> getavailUnits();
    std::vector<Unit> getunits();
    std::string getname();
    std::string getrace();
    
    void setavailUnits(std::vector<Unit> availUnits);
    void setunits(std::vector<Unit> units);
    void setname(std::string name);
    void setrace(std::string race);
    
    void loadAvailUnits();
    virtual int buildUnit(int unitNumber)=0;
};


#endif /* Player_hpp */
