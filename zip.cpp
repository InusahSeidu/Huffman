//Inusah Seidu
//Project 3
//CSC245
//zip.cpp

#include <iostream>
#include <string>
#include <fstream>
#include <cstring>
#include <filesystem>
#include "huffman.h"

using namespace std;

int main(int argc, char **argv)
{
    string filename = argv[2]; string text;
    int table[256];
    double count; double size; double compression;
    HuffmanTree h;
    if(strcmp(argv[1], "--help") == 0)
    {
       cout << "Usage: ZIP [OPTION]... [FILE]..." << endl;
       cout << "Compress a text file using Huffman encoding." << endl;
       cout << "\n --t              Display the Huffman encoding table." << endl;
       cout << " --help           Provide help on command." << endl;

    }
    else if(strcmp(argv[1], "--t") == 0)
    {
        ifstream f(filename.c_str());
        ofstream newfile(filename + ".zip");
        f.open(filename.c_str());
        if(f)
        {
            char ch;
            for(char ch = char(0); ch <= char(126); ch++)
            {
                table[ch] = 0;
            }
            fstream in(filename, fstream::in);
            while(in >> ch)
            {
                count++;
                table[ch] += 1;
                text.push_back(ch);
            }

            for(char ch = char(0); ch <= char(126); ch++)
            {
                if(table[ch] != 0)
                {
                    h.insert(ch, table[ch]);
                }
            }
            h.build();
            for(char ch = char(0); ch <= char(126); ch++)
            {
                if(table[ch] != 0)
                {
                    in << int(ch) << " " << h.GetCode(ch) << endl;
                }
            }
            for (char const &ch: text) 
            {
		        size += h.GetCode(ch).length();
                in << h.GetCode(ch);
            }
	
		    h.PrintTable();

			compression = 1 - (size/(count*8));
			cout << "File Successfully Compressed To " << size <<  " Bits (" << compression*100 << "% Less)." << endl;

		    
        }
        else
        {
            cout << "ZIP file " + filename + "does not exist" << endl;
        }
    }
    
    return 0;
}


