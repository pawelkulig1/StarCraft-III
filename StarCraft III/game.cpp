//
//  game.cpp
//  StarCraft III
//
//  Created by Paweł Kulig on 14.10.2017.
//  Copyright © 2017 Paweł Kulig. All rights reserved.
//

#include <stdio.h>
#include "game.h"

Game::Game()
{
    day = 0;
    int action = 0;
    while(true)
    {
        action = Ui::showMainMenu();
        //std::cout<<action<<std::endl;
        if(action == 1)
        {
            start();
        }
        
        if(action == 2)
        {
            Ui::showHighScores();
        }
        
        if(action == 3)
        {
            Ui::showRules();
        }
        
        if(action == 4)
        {
            endGame();
        }
    }
}

void Game::start()
{
    int action = 0;
    Player p;
    Player *player = &p;
    Mine m;
    Mine *mine = &m;
    
    player->loadAvailUnits();
    
    //set game difficulty level
    Game::difficulty = Ui::showLevelMenu();
    if(Game::difficulty == 1)
    {
        //Unit::additionalAttack = 0; //TODO
    }
    
    if(Game::difficulty == 2)
    {
        //Unit::additionalAttack = 2; //TODO
    }
    
    if(Game::difficulty == 3)
    {
        //Unit::additionalAttack = 4; //TODO
    }
    
    
    
    //Unit::additionalAttack =
    Attack::loadPossibleAttackers();
    
    //Game Loop
    while(1)
    {
        Ui::showStats(player->getname(), player->getresources(), day, player->getunits());
        
        action = Ui::showMainActions();
        
        //UPGRADE MINE
        if(action == 1)
        {
            Ui::clearScreen();
            int temp = mine->nextLevelCost(); //save this before upgrading
            int upgrade = mine->upgrade(player->getresources());
            if(upgrade == 1)
            {
                player->setresources(player->getresources() - temp);
            }
            
            if(upgrade == 0)
            {
                Ui::showMessage("Can't upgrade mine - not enough resources!");
            }
            
            if(upgrade == -1)
            {
                Ui::showMessage("Operation aborted by user");
            }
            
        }
        
        if(action == 2)
        {
            //upgrade defences
            int action = 0;
            Ui::clearScreen();
            /*action = ui.showBuildActions(availDefs);
            if(action == 1)
            {
                player.buildUnit(availDefs[0]);
            }
            
            if(action == 2)
            {
                player.buildUnit(availDefs[1]);
            }
            
            if(action == 3)
            {
                player.buildUnit(availDefs[2]);
            }*/
        }
        
        if(action == 3)
        {
            day++;
            player->setresources(player->getresources() + mine->getExtraction());
            
            //attack or not
            Attack attack(day);
            bool result;
            //std::vector <Unit> temp;
            //temp = player->getunits();
            result = attack.battle(player);
            if(result == 0) //game end
            {
                endGame(player);
            }
            
            player->setunits(temp);
        }
    }
    
}

void Game::endGame(Player player)
{
    std::cout<<"GAME OVER!"<<std::endl;
    std::cout<<player.getname()<<" you have gained: "<<day*100<<" points."<<std::endl;
    CSVparser parser("highscores");
    parser.addHighscore(player.getname(), day * 100 * Game::difficulty);
    exit(0);
}

void Game::endGame()
{
    exit(0);
}

int Game::getdifficulty()
{
    return difficulty;
}
