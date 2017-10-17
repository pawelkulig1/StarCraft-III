#ifndef csvparser_h
#define csvparser_h

#include "libs.h"
#include <fstream>
#include "unit.h"


#define maxLines 20
#define maxWords 20

class CSVparser
{
    std::fstream file;
    std::string filename;
    std::string **text;

public:
    CSVparser(){};
    CSVparser(std::string filename);
    CSVparser(CSVparser &parser);

    ~CSVparser();
    
    std::string getfilename();
    void setfilename(std::string filename);

    void parse();
    void split(std::string line, std::string separator, std::string *retStr);
    void drawTable(bool header = 1);
    std::string getNameWithNumber(int number);//starting with 1
    int getIntAttributeOfName(std::string name, std::string attribute);
    std::string getstringAttributeOfName(std::string name, std::string attribute);
    //wtype enumConverter(std::string toConv);
    void addHighscore(std::string name, int highscore);
};

#endif
