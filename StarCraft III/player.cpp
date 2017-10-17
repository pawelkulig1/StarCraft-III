#include "player.h"


Player::Player(int startResources)
{
	//name
	std::cout<<"Hello officer what is your name? (type in)"<<std::endl;
	std::string temp;
	std::cin >> temp;
	setname(temp);
    Ui::clearScreen();
	std::cout<<"Welcome officer " + getname() + " you are in charge of this base! Be ready for attacks from all these stupid aliens!"<<std::endl;
    Ui::clearScreen(5);
	//sleep(5);
	setresources(startResources);
}

std::vector <Unit> Player::getdefenceUnits()
{
	return defenceUnits;
}

void Player::setdefenceUnits(std::vector <Unit> defenceUnits)
{
	this->defenceUnits = defenceUnits;
}

void Player::setname(std::string name)
{
	this->name = name;
}

std::string Player::getname()
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
        Ui::showMessage("Not enough resources to recruit: " + defence.getname());
	}

	return 0;
}
