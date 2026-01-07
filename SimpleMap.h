#pragma once
#include <string>
#include <iostream>
#include <fstream>
#include "BinaryCode.h"
using namespace std;

class SimpleMap
{
    BinaryCode table[256];

public:
    SimpleMap()
    {
        for (int i = 0; i < 256; i++)
        {
            table[i].length = 0;
            table[i].bits = 0;
        }
    }

    void insert(unsigned char ch, unsigned int bits, int length)
    {
        table[ch].bits = bits;
        table[ch].length = length;
    }

    BinaryCode get(unsigned char ch)
    {
        return table[ch];
    }
    void display()
    {
        for (int i = 0; i < 256; i++)
        {
            if (table[i].length > 0)
            {
                cout << (unsigned char)i << " : " << table[i].bits << " , " << table[i].length << endl;

                cout << endl;
            }
        }
    }

    void saveToFile(string filename)
    {
        ofstream out(filename);

        for (int i = 0; i < 256; i++)
        {
            if (table[i].length > 0)
            {
                out << i << " "
                    << table[i].bits << " "
                    << table[i].length << endl;
            }
        }

        out.close();
        cout << "Key map saved to " << filename << endl;
    }

    void loadFromFile(string filename)
    {
        ifstream in(filename);

        int ch;
        unsigned int bits;
        int length;

        for (int i = 0; i < 256; i++)
        {
            table[i].bits = 0;
            table[i].length = 0;
        }

        while (in >> ch >> bits >> length)
        {
            table[ch].bits = bits;
            table[ch].length = length;
        }

        in.close();
    }
};
