#include "huffman.h"
#include <iostream>
using namespace std;

HuffmanTree:: HuffmanTree()
	: numChars(0), built(false) {}

void HuffmanTree:: insert(char ch, int weight) {
    HNode newNode = {ch, weight, -1, -1}; 
    built = false;
    nodes.push_back(newNode);
    numChars++;

}

bool HuffmanTree:: inTree(char ch) {
    //checks each node to see if it matches input
    bool check = false;
    for(int i = 0; i < nodes.size(); i++)
    {
        if(nodes[i].ch == ch)
        {
            check = false;
        }
    }
    return check;
}

int HuffmanTree:: GetFrequency(char ch) {
    //gets the frequency of a character if it is in the tree
    int frequency = 0;
    if(inTree(ch))//if the input is in the tree
    {
        for(int i = 0; i < nodes.size(); i++)
        {
            if(nodes[i].ch == ch)
            {
                frequency = nodes[i].weight;
                return frequency;
            }
            else
            {
                return 0;
            }
        }
    }
}

int HuffmanTree:: GetFrequency(int i) {

}

int HuffmanTree:: lookUp(char ch) 
{
    if (inTree(ch))
    {
                for(int i = 0; i < nodes.size(); i++)
                {
                        if (nodes[i].ch == ch)
                        {
                                return i;
                        }
                }
    }
}

string HuffmanTree:: GetCode(char ch) {

//Calls a method with the index of wanted character;
//Returns the binary representation of the given character
         return GetCode(lookUp(ch));
}


string HuffmanTree:: GetCode(int i) 
{
    string code;
    if (nodes[i].parent == 0)
		code = " ";
	else
        code = GetCode(nodes[i].parent) + (char) (nodes[i].childType+'0');

    return code;
}

void HuffmanTree:: PrintTable() 
{
    cout << "     ++++ ENCODING TABLE FOR ZIP FILE ++++       " << endl;
    cout << "\n     INDEX       CHAR        WEIGHT      PARENT      CHILDTYPE" << endl;
    for(int i = 0; i < nodes.size(); i++)
    {
        if (nodes[i].ch != char(0) && nodes[i].ch != '\n' && nodes[i].ch != ' ')
        {
			cout <<  "        " << i <<  nodes[i].ch; 

        }
    }
}

int HuffmanTree:: numNodes() {
//will return the amount of nodes in the tree
    return nodes.size();

}

void HuffmanTree:: build() {
    //builds the tree and iterates 
    int tableSize = nodes.size();
    int index1 = 0; int index2 = 0;
    int freq1 = 0;  int freq2 = 0;

    for(int i = 0; i < tableSize; i++)
    {

        for(int j = 0; j < nodes.size(); j++)
        {
            if(nodes[i].parent == -1 || nodes[i].parent == 0)
            {
                if(nodes[i].weight < freq1 || freq1 == 0)
                {
                    if(freq1 < freq2)
                    {
                        freq2 = freq1;
                        index2 = index1;
                    }

                    freq1 = nodes[i].weight;
                    index1 = i;
                }
                else if(nodes[i].weight < freq2 ||freq2 == 0)
                {
                    freq2 = nodes[i].weight;
                    index2 = 1;
                }
            }
        }

    }
    
    HNode parentnode =   {char(0), freq1+freq2, 0, -1};
		nodes.push_back(parentnode);
		nodes[index1].parent = nodes.size()-1;
		nodes[index1].childType = 0;
		nodes[index2].parent = nodes.size()-1;
		nodes[index2].childType = 1;
}
