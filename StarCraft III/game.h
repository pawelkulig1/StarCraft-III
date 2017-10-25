//
//  game.h
//  StarCraft III
//
//  Created by Paweł Kulig on 14.10.2017.
//  Copyright © 2017 Paweł Kulig. All rights reserved.
//

#ifndef game_h
#define game_h

#include "player.h"
#include "Units/UnitTerran.hpp"
#include "Units/UnitProtos.hpp"
#include "Units/UnitZerg.hpp"
#include "Units/unit.h"
#include "ui.h"
#include "mine.h"
#include "attack.h"

class Game
{
    Ui ui;
    int day;
    
public:
    static int counter;
    static int difficulty;
    Game();
private:
    void start();
    void endGame(Player *player);
    void endGame();
    int getdifficulty();
};


#endif /* game_h */
