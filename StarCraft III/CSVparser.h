#ifndef csvparser_h
#define csvparser_h

#include "libs.h"
#include <fstream>
#include "unit.h"


#define maxLines 20
#define maxWords 20

class CSVparser
{
    fstream file;
    string filename;
    string **text;

    public:
        void setfilename(string filename);
        string getfilename();
        CSVparser(){};
        CSVparser(string filename);

        ~CSVparser();

        void parse();
        void split(string line, string separator, string *retStr);
        void drawTable(bool header = 1);
        string getNameWithNumber(int number);//starting with 1
        int getIntAttributeOfName(string name, string attribute);
        string getStringAttributeOfName(string name, string attribute);
        //wtype enumConverter(string toConv);
        void addHighscore(string name, int highscore);
};

#endif