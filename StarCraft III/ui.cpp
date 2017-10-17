#include <iomanip>
#include "ui.h"

int Ui::showMainMenu()
{
	int choice;
	std::cout<<"Menu:"<<std::endl;
	std::cout<<"1) Start game"<<std::endl;
	std::cout<<"2) Show highscores"<<std::endl;
	std::cout<<"3) Show rules of game"<<std::endl;
	std::cout<<"4) quit"<<std::endl;
	//std::cout<<flush;
	std::cin >> choice;
	return choice;
}

void Ui::showMessage(std::string message)
{
	clearScreen();
	std::cout<<message<<std::endl;
	clearScreen(3);
}

void Ui::showStats(std::string name, int resources, int day, std::vector <Unit> units)
{
	//clearScreen();
	std::cout<<"===================================="<<std::endl<<std::endl;
	std::cout<<"Name: "<<name<<" Resources: "<<resources<<" "<<"Day: "<<day<<std::endl<<std::endl;
	std::cout<<"Defences:"<<std::endl;
	if(units.size() == 0)
		std::cout<<"No defences available"<<std::endl;
	for(int i=0;i<units.size();i++)
	{
		std::cout<<"Name: "<<units[i].getname()<<" | HP: "<<units[i].gethp()<<"/"<<units[i].getmaxHp()<<std::endl;
	}

	std::cout<<std::endl<<std::endl<<"===================================="<<std::endl;
}

bool Ui::showMineStats(int level, int extraction, int nextLevelExtraction, int cost)
{
	std::cout<<"===================================="<<std::endl<<std::endl;
	std::cout<<"Mine level: "<<level<<std::endl;
	std::cout<<"current extraction: "<<extraction<<" next level extraction: "<<nextLevelExtraction<<" "<<"cost of upgrade: "<<cost<<std::endl<<std::endl;
	std::cout<<"===================================="<<std::endl;	
	return yesNoDialog(); //return if user want to upgrade
}

void Ui::showHighScores()
{
	clearScreen();
	std::string line;
	std::fstream file;
	std::cout<<"===================================="<<std::endl;
	std::cout<<"Highscores:"<<std::endl<<std::endl;
	file.open("highscores");
	if(file.is_open())
	{
		std::cout<<std::setw(23)<<std::left<<"| Name: "<<std::setw(6)<<std::left<<"| Score:"<<" |"<<std::endl;
		while ( getline (file,line) )
		{
			std::cout<<"| "<<std::setw(20)<< std::left <<line.substr(0, line.find(",")) << " | "<<std::setw(6)<<std::left<<line.substr(line.find(",")+1)<<" |"<<std::endl;
		}
	file.close();

	std::cout<<"===================================="<<std::endl;
	clearScreen(3);
    }
    else std::cout << "Unable to open file";
}

void Ui::showRules()
{	
	clearScreen();
	std::cout<<std::endl<<"===================================="<<std::endl<<std::endl;
	std::cout<<"Rules:"<<std::endl<<std::endl;
	std::cout<<"Aim of game is to survive aliens attacks by upgrading economy and defences"<<std::endl;
	std::cout<<std::endl<<"===================================="<<std::endl;
	clearScreen(3);
}

int Ui::showMainActions()
{
	int choice;
	//std::cout<<"Resources avaliable: "

	std::cout<<"What do you want to do today?"<<std::endl;
	std::cout<<"1) Upgrade your mine"<<std::endl;
	std::cout<<"2) Upgrade defenses"<<std::endl;
	std::cout<<"3) Next day"<<std::endl;
	std::cin >> choice;
	return choice;
}

int Ui::showLevelMenu()
{
    int choice;
    std::cout<<"What mode do you want to play?"<<std::endl;
    std::cout<<"1) Easy - I am noob"<<std::endl;
    std::cout<<"2) Medium - for normal guy"<<std::endl;
    std::cout<<"3) Hard - for instane protos killers"<<std::endl;
    std::cin >> choice;
    return choice;
}

void Ui::showDefenseStats()
{

}

int Ui::showBuildActions(std::vector <Unit> structure) //TODO std::vector
{
	clearScreen();
	int action = 0;
	std::cout<<"===================================="<<std::endl;

	std::cout<<std::setw(10)<<std::left<<"Option: ";
	std::cout<<std::setw(15)<<std::left<<"Name:"<<std::setw(40)<<std::left<<" Description: ";
	std::cout<<std::setw(10)<<std::left<<"  Type: "<<std::setw(10)<<std::left<< " Attack: ";
	std::cout<<std::setw(10)<<std::left<< " Max HP: "<<std::setw(10) <<std::left<<" Cost: "<<std::endl;
	for(int i=0;i<structure.size();i++)
	{
		std::cout<<std::setw(10)<<std::left<<i+1;
		std::cout<<std::setw(15)<<std::left<<structure[i].getname()<<std::setw(40)<<std::left<<structure[i].getdescription();
		std::cout<<std::setw(10)<<std::left<<structure[i].gettype()<<std::setw(10)<<std::left<<structure[i].getattack();
		std::cout<<std::setw(10)<<std::left<<structure[i].getmaxHp()<<std::setw(10)<<std::left<<structure[i].getcost()<<std::endl;
	}
	


	std::cout<<"===================================="<<std::endl;
	std::cout<<std::endl<<std::endl<<"Which one do you want to upgrade? (0 to cancel)"<<std::endl;
	//clearScreen(3);
	std::cin>>action;

	clearScreen();
	return action;

}

void Ui::clearScreen(int count)
{
	for(int i=0;i<count;i++)
	{
		std::cout<<std::endl;
	}
}

bool Ui::yesNoDialog(std::string text)
{
	std::string answer;
	std::cout<<text<<" (y/n): ";
	std::cin>>answer;
	while(1)
	{	
		if(answer == "y")
		{
			return 1;
		}

		if(answer == "n")
		{
			return 0;
		}
	}

}
