//Inusah Seidu
//Project 3
//CSC 245
//unzip.cpp

#include <iostream>
#include <fstream> 
#include <string>
#include <map>
using namespace std;

//method to read the file
void readFile(char **argv, map<string,char>& m);

int main(int argc, char **argv)
{
    map<string, char> m;//map of strings to chars
    //take file name of zip from command line
    readFile(argv,m);
}

void readFile(char **argv, map<string,char>& m)
{
    string filename = argv[1]; 
    ifstream infile(filename.c_str()); //file name used in method
    ofstream outfile; //output method for file 
    string newfile = filename;
    string outname = newfile.substr(0,newfile.length() - 4);//takes .zip off filename
    outfile.open(outname.c_str());

    string key; int size;
    //key for binary string
    //size for map size 
    int value;  infile >> size;
    //value is character that we must convert from Ascii
    for(int i = 1; i <= size ; i++)
    {
	    	infile >> value >> key;
		    m[key] = (char) value;
    }

    char ch;  string token;
    infile >> ch; token += ch;
    while (infile)
    {   
        map<string,char,less<string>>::iterator it = m.find(token);//less<string> starts from least string
        if (it!= m.end()) 
        {
            outfile << m[token];
            token = "";
        }

        infile >> ch;
        token += ch;
    }
    outfile.close();
    cout << "File Successfully Inflated Back To Original." << endl;
}

    
