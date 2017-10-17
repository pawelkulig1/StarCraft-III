#ifndef unit_h
#define unit_h
#include "CSVparser.h"

class Unit
{
    
	std::string name;
	std::string description;
	std::string type;
	int attack;
	int hp;
	int maxHp;
	int cost;
	bool alive; //1 - alive; 0 - dead

public:
    static int additionalAttack;
    //static int additionalHp;
    
    Unit(std::string name, std::string type, int attack, int maxHp);
    Unit();
    ~Unit();
    
    //GETTERS/SETTERS
    
    void setname(std::string name);
    std::string getname();
    
    void settype(std::string type);
    std::string gettype();

    void setattack(int attack);
    int getattack();

    void sethp(int hp);
    int gethp();

    void setmaxHp(int maxHp);
    int getmaxHp();

    void setcost(int cost);
    int getcost();

    void setdescription(std::string description);
    std::string getdescription();

    void setalive(bool alive);
    bool getalive();

    bool initializeFromFile(int number, std::string filename = "defences.csv");
    /* Initializes object with data from file.
    Number is number of line to initialize from.
    (1 obj. - 1 line)*/

    Unit operator*(Unit u);
    /*fight between two diffrent units
    std::left side strikes first but strike
    from both sides is guaranteed*/

    Unit operator+(Unit u);
    /*fight between two diffrent units
    std::left side strikes first if attacker
    kills defender, defender does not make dmg*/
};

#endif
