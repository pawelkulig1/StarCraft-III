#include "player.h"


Player::Player(int startResources)
{
	//name
	cout<<"Hello officer what is your name? (type in)"<<endl;
	string temp;
	cin >> temp;
	setname(temp);
	ui.clearScreen();
	cout<<"Welcome officer " + getname() + " you are in charge of this base! Be ready for attacks from all these stupid aliens!"<<endl;
	ui.clearScreen(5);
	//sleep(5);
	setresources(startResources);
}

vector <Unit> Player::getdefenceUnits()
{
	return defenceUnits;
}

void Player::setdefenceUnits(vector <Unit> defenceUnits)
{
	this->defenceUnits = defenceUnits;
}

void Player::setname(string name)
{
	this->name = name;
}

string Player::getname()
{
	return name;
}

void Player::setresources(int resources)
{
	this->resources = resources;
}

int Player::getresources()
{
	return resources;
}

int Player::buildDefence(Unit defence)
{
	if(defence.getcost()<resources)
	{
		defenceUnits.push_back(defence);
		resources-=defence.getcost();
	}
	else
	{
		ui.showMessage("Not enough resources to recruit: " + defence.getname());
	}

	return 0;
}