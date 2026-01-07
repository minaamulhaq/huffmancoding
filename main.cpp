#include <iostream>
#include "FrequencyCounter.h"
#include "myQueue.h"
#include "HuffmanNode.h"
#include "SimpleMap.h"
#include "HuffmanCompressor.h"
#include <string>
using namespace std;
int main()
{

	while (1)
	{
		string inputFile = "";
		string outputFile = "";

		string keyFile = "";
		SimpleMap map;
		cout << "Choose an option:\n1. Compress File\n2. Decompress File\nEnter choice (1 or 2): ";
		int choice;
		cin >> choice;
		if (choice == 1)
		{
			cout << "Enter the input file name: ";
			cin >> inputFile;
			cout << "Compressed File : ";
			cin >> outputFile;
			cout << "Enter File to store key map (for reference): ";
			cin >> keyFile;
			FrequencyCounter f;
			f.calculateFrequency(inputFile);
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

			root->generateCodes(root->getRoot(), 0, 0, map);

			HuffmanCompressor::compressFile(inputFile, outputFile, map);

			cout << "Compressed File created: " << outputFile << endl;
			
			map.saveToFile(keyFile);
			cout << "Compression completed." << endl;
			cout << "Original size: " << f.getFileSize() / 1024 << " KB" << endl;
			FrequencyCounter f2;
			f2.calculateFrequency(outputFile);
			cout << "compressed file size: " << f2.getFileSize() / 1024 << " KB" << endl;
			delete[] fb;
			delete root;
		}
		else if (choice == 2)
		{
			cout << "Enter the key file name: ";
			cin >> keyFile;
			map.loadFromFile(keyFile);
			cout << "Enter the compressed file name: ";
			cin >> inputFile;
			cout << "Enter the decompressed file name: ";
			cin >> outputFile;
			HuffmanCompressor::decompressFile(inputFile, outputFile, map);
			cout << "Decompression completed." << endl;
			cout << "Decompressed File created: " << outputFile << endl;
			FrequencyCounter f3;
			f3.calculateFrequency(outputFile);
			cout << "decompressed file size: " << f3.getFileSize() / 1024 << " KB" << endl;
		}

		else
		{
			break;
			cout << "Invalid choice. Please enter 1 or 2." << endl;
		}
	}

	return 0;
}
