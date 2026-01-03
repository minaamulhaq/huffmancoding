#include <iostream>
#include "FrequencyCounter.h"
#include "ImageRead.h"
#include "myQueue.h"
#include "HuffmanNode.h"
#include "SimpleMap.h"
#include "HuffmanCompressor.h"
#include <string>
using namespace std;
int main()
{

	string inputFile = "";
	string outputFile = "";
	cout << "Enter the input file name: ";
	cin >> inputFile;
	cout << "Compressed File : ";
	cin >> outputFile;

	FrequencyCounter f;
	f.calculateFrequency(inputFile);
	cout << "File size: " << f.getFileSize() / 1024 << " KB" << endl;
	int *fb = f.getFrequency();

	myQueue obj(256);

	for (int i = 0; i < 256; i++)
	{
		if (fb[i] > 0)
		{
			obj.enqueue(new HuffmanNode((unsigned char)i, fb[i]));
		}
	}

	HuffmanNode *root = HuffmanNode::buildHuffmanTree(obj);

	SimpleMap map;
	root->generateCodes(root->getRoot(), 0, 0, map);

	HuffmanCompressor::compressFile(inputFile, outputFile, map);
	cout << "Compression completed." << endl;

	cout << "Compressed File created: compressed.bin" << endl;

	FrequencyCounter f2;
	f2.calculateFrequency(outputFile);

	cout << "compressed file size: " << f2.getFileSize() / 1024 << " KB" << endl;
	string DecompressedFile = "";

	cout << "Enter the output file name or Decompressed File Name: ";
	cin >> DecompressedFile;

	HuffmanCompressor::decompressFile(outputFile, DecompressedFile, map);
	cout << "Decompression completed." << endl;
	cout << "Decompressed File created: " << DecompressedFile << endl;
	// decompressed file size
	FrequencyCounter f3;
	f3.calculateFrequency(DecompressedFile);
	cout << "decompressed file size: " << f3.getFileSize() / 1024 << " KB" << endl;

	delete[] fb;
	delete root;
	return 0;
}
