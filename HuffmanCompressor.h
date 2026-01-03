#pragma once
#include "SimpleMap.h"
#include "HuffmanNode.h"
#include <fstream>
using namespace std;
#include <unordered_map>
class HuffmanCompressor
{
public:
    static void compressFile(const string &inputFile, const string &outputFile, SimpleMap &map);
    static void decompressFile(const string &inputFile, const string &outputFile, SimpleMap &map);

private:
};

void HuffmanCompressor::compressFile(const string &inputFile, const string &outputFile, SimpleMap &map)
{
    ifstream in(inputFile, ios::binary);
    ofstream out(outputFile, ios::binary);

    unsigned char inByte;
    unsigned char buffer = 0; // temp byte to store bits
    int bufferLen = 0;        // how many bits in buffer

    while (in.read(reinterpret_cast<char *>(&inByte), 1))
    {
        BinaryCode code = map.get(inByte);
        unsigned int bits = code.bits;
        int len = code.length;

        for (int i = len - 1; i >= 0; i--)
        {
            buffer = (buffer << 1) | ((bits >> i) & 1);
            bufferLen++;

            if (bufferLen == 8)
            {
                out.write(reinterpret_cast<char *>(&buffer), 1);
                buffer = 0;
                bufferLen = 0;
            }
        }
    }

    // write remaining bits (if any) with padding 0
    if (bufferLen > 0)
    {
        buffer = buffer << (8 - bufferLen); // shift remaining bits to MSB
        out.write(reinterpret_cast<char *>(&buffer), 1);
    }

    in.close();
    out.close();
}

void HuffmanCompressor::decompressFile(const string &inputFile, const string &outputFile, SimpleMap &map)
{
    ifstream in(inputFile, ios::binary);
    ofstream out(outputFile, ios::binary);

    // Reverse map for decoding
    unordered_map<string, unsigned char> reverseMap;
    for (int i = 0; i < 256; i++)
    {
        BinaryCode code = map.get(i);
        if (code.length > 0)
        {
            string bitStr = "";
            for (int j = code.length - 1; j >= 0; j--)
            {
                bitStr += ((code.bits >> j) & 1) ? '1' : '0';
            }
            reverseMap[bitStr] = (unsigned char)i;
        }
    }

    unsigned char inByte;
    string bufferBits = "";

    while (in.read(reinterpret_cast<char *>(&inByte), 1))
    {
        // append bits to buffer
        for (int i = 7; i >= 0; i--)
        {
            bufferBits += ((inByte >> i) & 1) ? '1' : '0';

            // check if buffer matches any code
            auto it = reverseMap.find(bufferBits);
            if (it != reverseMap.end())
            {
                out.write(reinterpret_cast<char *>(&it->second), 1);
                bufferBits = "";
            }
        }
    }

    in.close();
    out.close();
}
