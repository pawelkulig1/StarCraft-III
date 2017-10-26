#ifndef ui_h
#define ui_h
#include <fstream>
#include "libs.h"
#include "CSVparser.h"
#include "Units/unit.h"
#include "Blasters.hpp"
#include "Shields.hpp"
#include "Healtkit.hpp"

class Ui
{
public:
    //GENERAL UTILITY
    static void clearScreen(int count=30);
    static bool yesNoDialog(std::string text="Are you sure you want to proceed?");
    static void showMessage(std::string message);
    static std::string getPlayerName();
    static std::string getPlayerRace();

    //MAIN MENU
    static int showMainMenu();
    static void showHighScores();
    static void showRules();

    //GAMEPLAY - MENU
    static void showStats(std::string name, int resources, int day, std::vector <Unit> units);
    static int showMainActions();
    static int showLevelMenu();

    //MINE
    static bool showMineStats(int level, int extraction, int nextLevelExtraction, int cost);
    
    //DEFENCE
    static int showBuildActions(std::vector <Unit> structure); //todo std::vector
    static void showDefenseStats();
    
    //LAB
    
    static int showTechnologyCategories(std::vector<ResearchOffensive> ofensive, std::vector<ResearchDefensive> defensive);
    static int showOfensiveTechnologyList(std::vector<ResearchOffensive> ofensive);
    static int showDefensiveTechnologyList(std::vector<ResearchDefensive> defensive);
    
    
    
};

#endif
