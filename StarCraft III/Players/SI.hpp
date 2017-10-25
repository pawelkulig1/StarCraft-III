//
//  SI.hpp
//  StarCraft III
//
//  Created by Paweł Kulig on 25.10.2017.
//  Copyright © 2017 Paweł Kulig. All rights reserved.
//

#ifndef SI_hpp
#define SI_hpp

#include <stdio.h>
#include "Player.hpp"
#include "unit.h"
#include "game.h"
#include <stdlib.h> //rand() srand()
#include <time.h> //time()

class SI: public Player
{
    int day;
    bool attackThisRound;
public:
    SI(int day);
    
    void setday(int day);
    int getday();
    
    void setattackThisRound(bool attackThisRound);
    bool getattackThisRound();
    
    void checkIfAttack();
    void createUnitsToAttack();
    bool battle(Player *player);
    void choseRace();
    
    int buildUnit(int unitNumber);
    
    
    
    
    
};

#endif /* SI_hpp */
