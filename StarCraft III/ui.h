#ifndef ui_h
#define ui_h
#include <fstream>
#include "libs.h"
#include "CSVparser.h"
#include "unit.h"

class Ui
{
	public:
		//GENERAL UTILITY
		void clearScreen(int count=30);
		bool yesNoDialog(string text="Are you sure you want to proceed?");
		void showMessage(string message);

		//MAIN MENU
		int showMainMenu();
		void showHighScores();
		void showRules();

		//GAMEPLAY - MENU
		void showStats(string name, int resources, int day, vector <Unit> units);
		int showMainActions();

		//MINE
		bool showMineStats(int level, int extraction, int nextLevelExtraction, int cost);
		
		//DEFENCE
		int showBuildActions(vector <Unit> structure); //todo vector
		void showDefenseStats();
		
};

#endif