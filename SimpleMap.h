#pragma once
#include <string>
#include <iostream>
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
};
