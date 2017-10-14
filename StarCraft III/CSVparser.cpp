#include "CSVparser.h"


void CSVparser::setfilename(string filename)
{
	this->filename = filename;
}

string CSVparser::getfilename()
{
	return filename;
}

CSVparser::CSVparser(string filename)
{
	this->filename = filename;
    file.open(filename, ios::in | ios::out);
    text = new string *[maxLines];

    for(int i=0;i<maxLines;i++)
    {
        text[i] = new string [maxWords];
    }
    //file.close();
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
	string line;
    int i=0;
    while(getline(file,line))
    {
        split(line, ",", text[i++]);
    }
}

void CSVparser::split(string line, string separator, string *retStr)
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
 			cout<<"| "<<i;
 		}
        for(int j=0;j<maxWords;j++)
        {
            if(text[i][j] == "")
                continue;
            cout<<" | "<<text[i][j];
        }
        cout<<" |"<<endl;
    }
}

string CSVparser::getNameWithNumber(int number)
{
	if(text[number][0] == "")
		return "-1";
	return text[number][0];

}

int CSVparser::getIntAttributeOfName(string name, string attribute)
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

string CSVparser::getStringAttributeOfName(string name, string attribute)
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

void CSVparser::addHighscore(string name, int highscore)
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

	//cout<<temp<<endl;
	filename = "resources/highscores";
	fstream file2;
    file2.open(filename, ios::trunc | ios::out);
    file2.close();


    file.clear(); //to be writeable
    
  //   cout<<"test1"<<endl;
    for(int i=0;i<maxLines-1;i++)
    {

    	if(text[i][0] == "" && i > temp)
			break;
    	if(i<temp)
    		file << text[i][0]<<","<<text[i][1]<<endl;
    	if(i>temp)
    		file << text[i-1][0]<<","<<text[i-1][1]<<endl;
    	if(i == temp)
		{
			file << name <<","<< highscore << endl;
			continue;
		}

    }	
    
    //file.close();
}

