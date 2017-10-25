//
//  SI.cpp
//  StarCraft III
//
//  Created by Paweł Kulig on 25.10.2017.
//  Copyright © 2017 Paweł Kulig. All rights reserved.
//

#include "SI.hpp"

SI::SI(int day)
{
    this->day = day;
    checkIfAttack();
    choseRace();
    loadAvailUnits();
    if(attackThisRound)
    {
        createUnitsToAttack();
    }
}

void SI::setadditionalAttack(int additionalAttack)
{
    this->additionalAttack = additionalAttack;
    for(int i=0;i<availUnits.size();i++)
    {
        availUnits[i].setattack(availUnits[i].getattack()+additionalAttack);
    }
}

int SI::getadditionalAttakc()
{
    return additionalAttack;
}

void SI::setday(int day)
{
    this->day = day;
}

int SI::getday()
{
    return day;
}

void SI::setattackThisRound(bool attackThisRound)
{
    this->attackThisRound = attackThisRound;
}

bool SI::getattackThisRound()
{
    return attackThisRound;
}

void SI::checkIfAttack()
{
    srand(time(NULL));
    int rnd = (rand()%10)+1;
    std::cout<<rnd<<" "<<day<<std::endl;
    if(day>rnd)
    {
        attackThisRound = 1;
    }
    else
    {
        attackThisRound = 0;
    }
}

void SI::createUnitsToAttack()
{
    //depends on day
    srand(time(NULL));
    for(int i=0;i<day;i++)
    {
        if(day<3)
        {
            buildUnit(0);
        }
        else
        {
            buildUnit(rand()%availUnits.size());
        }
    }
}

bool SI::battle(Player *player)
{
    std::vector <Unit> playerUnits;
    if(units.size()>0)
        std::cout<<"Attacking units:"<<std::endl<<std::endl;
    
    for(int i=0;i<units.size();i++)
    {
        std::cout<<units.at(i).getname()<<std::endl;
    }
    
    std::cout<<std::endl<<std::endl;
    if(units.size()>0)
        std::cout<<"Defending units:"<<std::endl<<std::endl;
    
    for(int i=0;i<player->getunits().size();i++)
    {
        playerUnits.push_back(player->getunits().at(i));
        std::cout<<playerUnits[i].getname()<<std::endl;
    }
    
    std::cout<<std::endl<<std::endl;
    
    
    //simulateBattle
    srand(time(NULL));
    while(true)
    {
        //delete all units with alive==0
        for(int i=0;i<units.size();i++)
        {
            if(units.at(i).getalive() == 0)
            {
                //std::cout<<"deleting units!"<<std::endl;
                units.erase(units.begin()+i);
                i=0;
            }
        }
        
        for(int i=0;i<playerUnits.size();i++)
        {
            if(playerUnits[i].getalive() == 0)
            {
                //std::cout<<"deleting defender!"<<std::endl;
                playerUnits.erase(playerUnits.begin()+i);
                i=0;
            }
        }
        //check if both sides have alive units
        
        if(units.size() == 0)
        {
            player->setunits(playerUnits);
            return 1;
        }
        
        if(playerUnits.size() == 0)
        {
            player->setunits(playerUnits);
            return 0;
        }
        
        //simulate fight
        
        int rnd1 = 0;
        int rnd2 = 0;
        
        rnd1 = round(rand()%(playerUnits.size()));
        rnd2 = round(rand()%(units.size()));
        if(Game::difficulty < 3)
            playerUnits[rnd1] = units[rnd2] * playerUnits[rnd1];
        else
            playerUnits[rnd1] = units[rnd2] + playerUnits[rnd1];
    }
}

void SI::choseRace()
{
    srand(time(NULL));
    int rnd = rand()%3;
    if(rnd == 0)
        setrace("T");
    if(rnd == 1)
        setrace("P");
    if(rnd == 2)
        setrace("Z");
}

int SI::buildUnit(int unitNumber)
{
    if(unitNumber > availUnits.size() || unitNumber < 0)
        return -1;
    
    units.push_back(availUnits[unitNumber]);
    return 1; //to get rid of compiler Xcode bullshit
}
