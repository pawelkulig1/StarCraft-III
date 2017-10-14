#include "libs.h"
#include "unit.h"

Unit::Unit(string name, string type, int attack, int maxHp)
{
	setname(name);
	settype(type);
	setattack(attack);
	sethp(maxHp); //initial hp is maxhp
	setmaxHp(maxHp);
	setalive(1);
}

Unit::Unit()
{
	setalive(1);
}

void Unit::setname(string name)
{
	this->name = name;
}

string Unit::getname()
{
	return name;
}

void Unit::settype(string type)
{
	this->type = type;
}

string Unit::gettype()
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

void Unit::setdescription(string description)
{
	this->description = description;
}

string Unit::getdescription()
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

bool Unit::initializeFromFile(int number, string filename)
{
	CSVparser parser(filename);
	parser.parse();
	name = parser.getNameWithNumber(number);
	if(name == "-1")
		return false; //row doesn't exists
	description = parser.getStringAttributeOfName(name, "Description");
	type = parser.getStringAttributeOfName(name, "Type");
	attack = parser.getIntAttributeOfName(name, "Attack");
	hp = maxHp = parser.getIntAttributeOfName(name, "Hp");
	cost = parser.getIntAttributeOfName(name, "Cost");
	
	return true;
}

Unit Unit::operator*(Unit u)
{
	int prevHp1 = u.gethp(), prevHp2 = this->gethp();

	u.sethp(u.gethp()-this->attack);
	cout<<this->getname()<<"["<<prevHp2<<" HP]"<<"("<<this->getattack()<<" dmg)--> "<<u.getname()<<"["<<prevHp1<<" HP --> "<<u.gethp()<<" HP]"<<endl;
	
	sethp(this->gethp() - u.getattack());

	cout<<u.getname()<<"["<<u.gethp()<<" HP]"<<"("<<u.getattack()<<" dmg)--> "<<this->getname()<<"["<<prevHp2<<" HP --> "<<this->gethp()<<" HP]"<<endl;
	cout<<endl;
	return u;
}

Unit Unit::operator+(Unit u)
{
	u.sethp(u.gethp()-this->attack);
	if(!u.getalive())
	{
		return u;
	}

	this->hp -= u.getattack();
	return u;

}