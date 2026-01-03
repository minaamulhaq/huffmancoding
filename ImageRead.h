#pragma once
#include <iostream>
#include <string>
#include <fstream>
using namespace std;
class ImageRead
{
	string inputFileName;
	string outputFileName;
	double size;

public:
	ImageRead(const string &inputFile, const string &outputFile);
	bool readAndSaveToTxt();
	double getImageSize();
};

ImageRead::ImageRead(const string &inputFile, const string &outputFile)
{
	inputFileName = inputFile;
	outputFileName = outputFile;
	size = 0;
}

bool ImageRead::readAndSaveToTxt()
{
	ifstream imageFile(inputFileName, ios::binary);
	ofstream textFile(outputFileName);

	if (!imageFile)
	{
		cerr << "Error: Cannot open image file " << inputFileName << endl;
		return false;
	}

	if (!textFile)
	{
		cerr << "Error: Cannot open output file " << outputFileName << endl;
		return false;
	}

	unsigned char byte;
	int count = 0;

	while (imageFile.read((char *)&byte, 1))
	{
		textFile << (int)byte << " ";
		count++;
	}
	size = count;
	cout << "Image successfully saved to text file." << endl;
	cout << "Total bytes written: " << count << endl;

	imageFile.close();
	textFile.close();
	return true;
}
double ImageRead::getImageSize()
{
	return size;
}
