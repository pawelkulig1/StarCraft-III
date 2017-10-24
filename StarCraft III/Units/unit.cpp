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

Unit::Unit(Unit &unit)
{
    this->name = unit.getname();
    this->description = unit.getdescription();
    this->type = unit.gettype();
    this->attack = unit.getattack();
    this->hp = unit.gethp();
    this->maxHp = unit.getmaxHp();
    this->cost = unit.getcost();
    this->alive = unit.getalive();
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

std::string Unit::getfilepath()
{
    return this->filepath;
}

void Unit::setfilepath(std::string filepath)
{
    this->filepath = filepath;
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

bool Unit::initializeFromFile(int number)
{
    CSVparser parser(this->getfilepath());
    parser.parse();
    setname(parser.getNameWithNumber(number));
    if(getname() == "-1")
        return false; //row doesn't exists
    setdescription(parser.getstringAttributeOfName(getname(), "Description"));
    settype(parser.getstringAttributeOfName(getname(), "Type"));
    setattack(parser.getIntAttributeOfName(getname(), "Attack"));
    sethp(parser.getIntAttributeOfName(getname(), "Hp"));
    setmaxHp(gethp());
    setcost(parser.getIntAttributeOfName(getname(), "Cost"));
    
    return true;
}
