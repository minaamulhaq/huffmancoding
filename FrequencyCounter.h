
#include <string>
#include <fstream>
#include <iostream>
using namespace std;
class FrequencyCounter
{
private:
    int *freq;
    int size;

public:
    FrequencyCounter();
    ~FrequencyCounter();
    void calculateFrequency(const string &imageFileName);
    void displayFrequency();
    int *getFrequency();
    int getFileSize();
};

FrequencyCounter::FrequencyCounter()
{
    freq = new int[256];
    for (int i = 0; i < 256; i++)
    {
        freq[i] = 0;
    }
    size = 0;
}
FrequencyCounter::~FrequencyCounter()
{
    delete[] freq;
}
void FrequencyCounter::calculateFrequency(const string &imageFileName)
{
    ifstream imageFile(imageFileName, ios::binary);

    if (!imageFile)
    {
        cerr << "Error: Cannot open image file " << imageFileName << endl;
        return;
    }

    unsigned char byte;

    while (imageFile.read((char *)&byte, 1))
    {
        freq[byte]++;
        size++;
    }

    imageFile.close();
    cout << "Image readed sunncesfully " << endl;
}
void FrequencyCounter::displayFrequency()
{
    for (int i = 0; i < 256; i++)
    {
        if (freq[i] > 0)
        {
            cout << "Byte " << i << " : " << freq[i] << endl;
        }
    }
}
int FrequencyCounter::getFileSize()
{
    return size;
}
int *FrequencyCounter::getFrequency()
{

    int *output = new int[256];

    for (int i = 0; i < 256; i++)
    {
        output[i] = freq[i];
    }
    return output;
}
