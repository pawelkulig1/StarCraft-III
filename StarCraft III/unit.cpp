#include "libs.h"
#include "unit.h"

Unit::Unit(std::string name, std::string type, int attack, int maxHp)
{
	setname(name);
	settype(type);
	setattack(attack);
	sethp(maxHp); //initial hp is maxhp
	setmaxHp(maxHp);
	setalive(1);
    //Unit::objCounter++;
}

Unit::Unit()
{
	setalive(1);
    //Unit::objCounter++;
}

Unit::~Unit()
{
    //Unit::objCounter--;
}

void Unit::setname(std::string name)
{
	this->name = name;
}

std::string Unit::getname()
{
	return name;
}

void Unit::settype(std::string type)
{
	this->type = type;
}

std::string Unit::gettype()
{
	return type;
}

void Unit::setattack(int attack)
{
	this->attack = attack;
}

int Unit::getattack()
{
	return attack;
}

void Unit::sethp(int hp)
{
	if(hp<=0)
		alive = 0;
	this->hp = hp;

}

int Unit::gethp()
{
	return hp;
}

void Unit::setmaxHp(int maxHp)
{
	this->maxHp = maxHp;
}

int Unit::getmaxHp()
{
	return maxHp;
}

void Unit::setcost(int cost)
{
	this->cost = cost;
}

int Unit::getcost()
{
	return cost;
}

void Unit::setdescription(std::string description)
{
	this->description = description;
}

std::string Unit::getdescription()
{
	return description;
}

void Unit::setalive(bool alive)
{
	this->alive = alive;
}
bool Unit::getalive()
{
	return alive;
}

bool Unit::initializeFromFile(int number, std::string filename)
{
	CSVparser parser(filename);
	parser.parse();
	name = parser.getNameWithNumber(number);
	if(name == "-1")
		return false; //row doesn't exists
	description = parser.getstringAttributeOfName(name, "Description");
	type = parser.getstringAttributeOfName(name, "Type");
	attack = parser.getIntAttributeOfName(name, "Attack");
	hp = maxHp = parser.getIntAttributeOfName(name, "Hp");
	cost = parser.getIntAttributeOfName(name, "Cost");
	
	return true;
}

Unit Unit::operator*(Unit u)
{
	int prevHp1 = u.gethp(), prevHp2 = this->gethp();

    u.sethp(u.gethp()-(this->attack + Unit::additionalAttack));
    std::cout<<this->getname()<<"["<<prevHp2<<" HP]"<<"("<<this->getattack() + Unit::additionalAttack<<" dmg)--> "<<u.getname()<<"["<<prevHp1<<" HP --> "<<u.gethp()<<" HP]"<<std::endl;
	
	sethp(this->gethp() - u.getattack());

	std::cout<<u.getname()<<"["<<u.gethp()<<" HP]"<<"("<<u.getattack()<<" dmg)--> "<<this->getname()<<"["<<prevHp2<<" HP --> "<<this->gethp()<<" HP]"<<std::endl;
	std::cout<<std::endl;
	return u;
}

Unit Unit::operator+(Unit u)
{
    int prevHp1 = u.gethp(), prevHp2 = this->gethp();
    
    u.sethp(u.gethp()-(this->attack + Unit::additionalAttack));
    std::cout<<this->getname()<<"["<<prevHp2<<" HP]"<<"("<<this->getattack() + Unit::additionalAttack<<" dmg)--> "<<u.getname()<<"["<<prevHp1<<" HP --> "<<u.gethp()<<" HP]"<<std::endl;
	
    if(!u.getalive())
	{
		return u;
	}

    sethp(this->gethp() - u.getattack());
    
    std::cout<<u.getname()<<"["<<u.gethp()<<" HP]"<<"("<<u.getattack()<<" dmg)--> "<<this->getname()<<"["<<prevHp2<<" HP --> "<<this->gethp()<<" HP]"<<std::endl;
    std::cout<<std::endl;
    return u;

}
