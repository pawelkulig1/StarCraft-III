#ifndef ui_h
#define ui_h
#include <fstream>
#include "libs.h"
#include "CSVparser.h"
#include "Units/unit.h"

class Ui
{
public:
    //GENERAL UTILITY
    static void clearScreen(int count=30);
    bool yesNoDialog(std::string text="Are you sure you want to proceed?");
    static void showMessage(std::string message);

    //MAIN MENU
    int showMainMenu();
    void showHighScores();
    void showRules();

    //GAMEPLAY - MENU
    void showStats(std::string name, int resources, int day, std::vector <Unit> units);
    int showMainActions();
    int showLevelMenu();

    //MINE
    bool showMineStats(int level, int extraction, int nextLevelExtraction, int cost);
    
    //DEFENCE
    int showBuildActions(std::vector <Unit> structure); //todo std::vector
    void showDefenseStats();
    
};

#endif
