#include "libs.h"

#include "player.h"
#include "unit.h"
#include "ui.h"
#include "mine.h"
#include "attack.h"

class Game
{
	Ui ui;
	int day;

	public:
		Game()
		{
			day = 0;
			int action = 0;
			while(true)
			{
				action = ui.showMainMenu();
				//cout<<action<<endl;
				if(action == 1)
				{
					start();
				}

				if(action == 2)
				{
					ui.showHighScores();
				}

				if(action == 3)
				{
					ui.showRules();
				}

				if(action == 4)
				{
					endGame();
				}
			}
		}
	private:
		void start()
		{
			int action = 0;
			Player player;
			Mine mine;
			vector <Unit> availDefs;
			

			//Create Defences
			Unit temp;
			int i=0; //1 because 0 line in file is header
			while(temp.initializeFromFile(i+1))
			{
				availDefs.push_back(temp);
				i++;
			}

			//Game Loop

			while(1)
			{
				ui.showStats(player.getname(), player.getresources(), day, player.getdefenceUnits());

				action = ui.showMainActions();

				//UPGRADE MINE
				if(action == 1)
				{
					ui.clearScreen();
					int temp = mine.nextLevelCost(); //save this before upgrading
					int upgrade = mine.upgrade(player.getresources());
					if(upgrade == 1)
					{
						player.setresources(player.getresources() - temp);
					}

					if(upgrade == 0)
					{
						ui.showMessage("Can't upgrade mine - not enough resources!");
					}

					if(upgrade == -1)
					{
						ui.showMessage("Operation aborted by user");
					}
					
				}

				if(action == 2)
				{
					//upgrade defences
					int action = 0;
					ui.clearScreen();
					action = ui.showBuildActions(availDefs);
					if(action == 1)
					{
						player.buildDefence(availDefs[0]);
					}

					if(action == 2)
					{
						player.buildDefence(availDefs[1]);
					}

					if(action == 3)
					{
						player.buildDefence(availDefs[2]);
					}
				}

				if(action == 3)
				{
					day++;
					player.setresources(player.getresources() + mine.getExtraction());

					//attack or not
					Attack attack(day);
					bool result;
					vector <Unit> temp;
					temp = player.getdefenceUnits();
					result = attack.battle(&temp);
					if(result == 0) //game end
					{
						endGame(player);
					}

					player.setdefenceUnits(temp);
				}
			}

		}

		void endGame(Player player)
		{
			cout<<"GAME OVER!"<<endl;
			cout<<player.getname()<<" you have gained: "<<day*100<<" points."<<endl;
			CSVparser parser("resources/highscores");
			parser.addHighscore(player.getname(), day*100);
			exit(0);
		}

		void endGame()
		{
			exit(0);
		}
};

int main()
{
	Game game;
	return 0;
}