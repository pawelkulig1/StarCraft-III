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
    Human p;
    Human *player = &p;
    
    SI s(0);
    SI *si = &s;
    
    Mine m;
    Mine *mine = &m;
    
    Blasters blasters;
    Shields shields;
    Healthkit healthkit;
    
    std::vector<ResearchDefensive> def;
    std::vector<ResearchOffensive> off;
    
    off.push_back(blasters);
    def.push_back(shields);
    def.push_back(healthkit);
    
    int action = 0;
    
    //set game difficulty level
    Game::difficulty = Ui::showLevelMenu();
    if(Game::difficulty == 1)
    {
        si->setadditionalAttack(0);
    }
    
    if(Game::difficulty == 2)
    {
        si->setadditionalAttack(2);
    }
    
    if(Game::difficulty == 3)
    {
        si->setadditionalAttack(4);
    }
    
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
            action = Ui::showBuildActions(player->getavailUnits());
            if(action != -1)
            {
                player->buildUnit(action-1);
            }
        }
        
        //Researches
        if(action == 3)
        {
            int action = 0;
            action = Ui::showTechnologyCategories(off, def);
            if(action == 0)
                continue;
            if(action > 100 && action < 200) //offensive
            {
                action = action%100; //getting rid of 100
                if(action == 1)
                {
                    if(off[0].getcost()<=player->getresources())
                    {
                        off[0].setlvl(1);
                        player->setadditionalAttack(off[0].getbonus());
                        player->setresources(player->getresources()-off[0].getcost());
                    }
                    else
                        Ui::showMessage("Not enough resources");
                }
            }
            
            if(action > 200 && action <300) //defensive
            {
                action = action%200;
                if(action == 1)
                {
                    if(def[0].getcost()<=player->getresources())
                    {
                        def[0].setlvl(1);
                        player->setadditionalHp(def[0].getbonus());
                        player->setresources(player->getresources()-def[0].getcost());
                    }
                    else
                        Ui::showMessage("Not enough resources");
                }
                if(action == 2)
                {
                    if(def[1].getcost()<=player->getresources())
                    {
                        def[1].setlvl(1);
                        player->setadditionalHp(def[1].getbonus());
                        player->setresources(player->getresources()-def[1].getcost());
                    }
                    else
                    {
                        Ui::showMessage("Not enough resources");
                    }
                }
            }
        }
        
        if(action == 4)
        {
            day++;
            player->setresources(player->getresources() + mine->getExtraction());
            
            //attack or not
            
            si->checkIfAttack();
            
            bool result= 1;
            if(si->getattackThisRound())
            {
                si->createUnitsToAttack();
                result = si->battle(player);
            }
            
            if(result == 0) //game end
            {
                endGame(player);
            }
            
            si->setday(day);
        }
    }
    
}

void Game::endGame(Player *player)
{
    std::cout<<"GAME OVER!"<<std::endl;
    std::cout<<player->getname()<<" you have gained: "<<day*100*Game::difficulty<<" points."<<std::endl;
    CSVparser parser("highscores");
    parser.addHighscore(player->getname(), day * 100 * Game::difficulty);
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
