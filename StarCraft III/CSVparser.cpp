#include "CSVparser.h"


void CSVparser::setfilename(std::string filename)
{
	this->filename = filename;
}

CSVparser::CSVparser(CSVparser &parser)
{
    filename = parser.getfilename();
    
    file.open(filename, std::ios::in | std::ios::out);
    text = new std::string *[maxLines];
    
    for(int i=0;i<maxLines;i++)
    {
        text[i] = new std::string [maxWords];
    }
    
    parse();
}

CSVparser::CSVparser(std::string filename)
{
	this->filename = filename;
    file.open(filename, std::ios::in | std::ios::out);
    text = new std::string *[maxLines];

    for(int i=0;i<maxLines;i++)
    {
        text[i] = new std::string [maxWords];
    }
    //file.close();
}

std::string CSVparser::getfilename()
{
    return filename;
}

CSVparser::~CSVparser()
{
	for(int i=0;i<maxLines;i++)
	{
		delete [] text[i];
		file.close();
	}
}

void CSVparser::parse()
{
	std::string line;
    int i=0;
    while(getline(file,line))
    {
        split(line, ",", text[i++]);
    }
}

void CSVparser::split(std::string line, std::string separator, std::string *retStr)
{
    int poz=0, prevPoz=0, i=0;
    while(1)
    {
        prevPoz = poz;
        if(poz == -1)
            break;
        poz = line.find(separator, poz+1);
        if(i != 0)
            prevPoz++;
        retStr[i++] = line.substr(prevPoz, poz-prevPoz);
    }
}

void CSVparser::drawTable(bool header)
{
    for(int i=0;i<maxLines;i++)
    {
    	if(text[i][0] == "")
            continue;

 		if(i!=0 or header == 0)
 		{
 			std::cout<<"| "<<i;
 		}
        for(int j=0;j<maxWords;j++)
        {
            if(text[i][j] == "")
                continue;
            std::cout<<" | "<<text[i][j];
        }
        std::cout<<" |"<<std::endl;
    }
}

std::string CSVparser::getNameWithNumber(int number)
{
	if(text[number][0] == "")
		return "-1";
	return text[number][0];

}

int CSVparser::getIntAttributeOfName(std::string name, std::string attribute)
{
	for(int i=0;i<maxLines;i++)
    {
    	if(text[i][0] == "")
            continue;

        if(text[i][0] == name)
        {
        	for(int j=0;j<maxWords;j++)
        	{
        		if(text[0][j] == attribute)
        		{
        			return stoi(text[i][j]);
        		}
        	}
        }
    }
    return -1;
}

std::string CSVparser::getstringAttributeOfName(std::string name, std::string attribute)
{
	for(int i=0;i<maxLines;i++)
    {
    	if(text[i][0] == "")
            continue;

        if(text[i][0] == name)
        {
        	for(int j=0;j<maxWords;j++)
        	{
        		if(text[0][j] == attribute)
        		{
        			return text[i][j];
        		}
        	}
        }
    }
    return "-1";
}

void CSVparser::addHighscore(std::string name, int highscore)
{
	int temp = 0;
	//where to put our highscore
	parse();
	//drawTable(0);
	for(int i=0;i<maxLines; i++)
	{
		if(text[i][1]=="")
		{
			temp = i;
			break;
		}
		if(stoi(text[i][1]) < highscore)
		{
			temp = i;
			break;
		}
	}

	//std::cout<<temp<<std::endl;
	filename = "resources/highscores";
	std::fstream file2;
    file2.open(filename, std::ios::trunc | std::ios::out);
    file2.close();


    file.clear(); //to be writeable
    
  //   std::cout<<"test1"<<std::endl;
    for(int i=0;i<maxLines-1;i++)
    {

    	if(text[i][0] == "" && i > temp)
			break;
    	if(i<temp)
    		file << text[i][0]<<","<<text[i][1]<<std::endl;
    	if(i>temp)
    		file << text[i-1][0]<<","<<text[i-1][1]<<std::endl;
    	if(i == temp)
		{
			file << name <<","<< highscore << std::endl;
			continue;
		}

    }	
    
    //file.close();
}

