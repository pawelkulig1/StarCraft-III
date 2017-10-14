#include <iomanip>
#include "ui.h"

int Ui::showMainMenu()
{
	int choice;
	cout<<"Menu:"<<endl;
	cout<<"1) Start game"<<endl;
	cout<<"2) Show highscores"<<endl;
	cout<<"3) Show rules of game"<<endl;
	cout<<"4) quit"<<endl;
	//cout<<flush;
	cin >> choice;
	return choice;
}

void Ui::showMessage(string message)
{
	clearScreen();
	cout<<message<<endl;
	clearScreen(3);
}

void Ui::showStats(string name, int resources, int day, vector <Unit> units)
{
	//clearScreen();
	cout<<"===================================="<<endl<<endl;
	cout<<"Name: "<<name<<" Resources: "<<resources<<" "<<"Day: "<<day<<endl<<endl;
	cout<<"Defences:"<<endl;
	if(units.size() == 0)
		cout<<"No defences available"<<endl;
	for(int i=0;i<units.size();i++)
	{
		cout<<"Name: "<<units[i].getname()<<" | HP: "<<units[i].gethp()<<"/"<<units[i].getmaxHp()<<endl;
	}

	cout<<endl<<endl<<"===================================="<<endl;
}

bool Ui::showMineStats(int level, int extraction, int nextLevelExtraction, int cost)
{
	cout<<"===================================="<<endl<<endl;
	cout<<"Mine level: "<<level<<endl;
	cout<<"current extraction: "<<extraction<<" next level extraction: "<<nextLevelExtraction<<" "<<"cost of upgrade: "<<cost<<endl<<endl;
	cout<<"===================================="<<endl;	
	return yesNoDialog(); //return if user want to upgrade
}

void Ui::showHighScores()
{
	clearScreen();
	string line;
	fstream file;
	cout<<"===================================="<<endl;
	cout<<"Highscores:"<<endl<<endl;
	file.open("resources/highscores");
	if (file.is_open())
	{
		cout<<setw(23)<<left<<"| Name: "<<setw(6)<<left<<"| Score:"<<" |"<<endl;
		while ( getline (file,line) )
		{
			cout<<"| "<<setw(20)<< left <<line.substr(0, line.find(",")) << " | "<<setw(6)<<left<<line.substr(line.find(",")+1)<<" |"<<endl;
		}
	file.close();

	cout<<"===================================="<<endl;
	clearScreen(3);
}

  else cout << "Unable to open file"; 
}

void Ui::showRules()
{	
	clearScreen();
	cout<<endl<<"===================================="<<endl<<endl;
	cout<<"Rules:"<<endl<<endl;
	cout<<"Aim of game is to survive aliens attacks by upgrading economy and defences"<<endl;
	cout<<endl<<"===================================="<<endl;
	clearScreen(3);
}

int Ui::showMainActions()
{
	int choice;
	//cout<<"Resources avaliable: "

	cout<<"What do you want to do today?"<<endl;
	cout<<"1) Upgrade your mine"<<endl;
	cout<<"2) Upgrade defenses"<<endl;
	cout<<"3) Next day"<<endl;
	cin >> choice;
	return choice;
}

void Ui::showDefenseStats()
{

}

int Ui::showBuildActions(vector <Unit> structure) //TODO vector
{
	clearScreen();
	int action = 0;
	cout<<"===================================="<<endl;

	cout<<setw(10)<<left<<"Option: ";
	cout<<setw(15)<<left<<"Name:"<<setw(40)<<left<<" Description: ";
	cout<<setw(10)<<left<<"  Type: "<<setw(10)<<left<< " Attack: ";
	cout<<setw(10)<<left<< " Max HP: "<<setw(10) <<left<<" Cost: "<<endl;
	for(int i=0;i<structure.size();i++)
	{
		cout<<setw(10)<<left<<i+1;
		cout<<setw(15)<<left<<structure[i].getname()<<setw(40)<<left<<structure[i].getdescription();
		cout<<setw(10)<<left<<structure[i].gettype()<<setw(10)<<left<<structure[i].getattack();
		cout<<setw(10)<<left<<structure[i].getmaxHp()<<setw(10)<<left<<structure[i].getcost()<<endl;
	}
	


	cout<<"===================================="<<endl;
	cout<<endl<<endl<<"Which one do you want to upgrade? (0 to cancel)"<<endl;
	//clearScreen(3);
	cin>>action;

	clearScreen();
	return action;

}

void Ui::clearScreen(int count)
{
	for(int i=0;i<count;i++)
	{
		cout<<endl;
	}
}

bool Ui::yesNoDialog(string text)
{
	string answer;
	cout<<text<<" (y/n): ";
	cin>>answer;
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