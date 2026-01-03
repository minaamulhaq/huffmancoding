# Huffman Compression Project

A C++ implementation of Huffman coding for file compression and decompression. This project uses the Huffman algorithm to efficiently compress files by building an optimal binary tree based on character frequency.

## Features

- **File Compression**: Compress any file using Huffman coding algorithm
- **File Decompression**: Restore compressed files to their original form
- **Frequency Analysis**: Calculate and analyze character frequency in files
- **Binary Encoding**: Efficient bit-level encoding and decoding
- **File Size Reporting**: Display original, compressed, and decompressed file sizes

## Project Structure

```
├── main.cpp                 # Main program entry point
├── HuffmanCompressor.h      # Compression/decompression logic
├── HuffmanNode.h            # Huffman tree node definition
├── HuffmanNode.cpp          # Huffman tree node implementation
├── FrequencyCounter.h       # Character frequency calculation
├── BinaryCode.h             # Binary code representation
├── SimpleMap.h              # Character to code mapping
├── myQueue.h                # Priority queue implementation
├── Queue.h                  # Queue utilities
├── Node.h                   # Generic node structure
└── ImageRead.h              # File reading utilities
```

## How It Works

1. **Frequency Analysis**: Calculate the frequency of each byte in the input file
2. **Build Huffman Tree**: Create a binary tree where frequent characters have shorter codes
3. **Generate Codes**: Generate binary codes for each character based on tree traversal
4. **Compress**: Replace characters with their Huffman codes and write to output file
5. **Decompress**: Read compressed file and reconstruct original data using the Huffman tree

## Usage

### Compilation

```bash
g++ -o huffman main.cpp HuffmanNode.cpp -std=c++11
```

### Running the Program

```bash
./huffman
```

The program will prompt you for:
1. Input file name (file to compress)
2. Compressed output file name
3. Decompressed output file name

### Example

```
Enter the input file name: input.txt
Compressed File: compressed.bin
File size: 10 KB
Compression completed.
Compressed File created: compressed.bin
compressed file size: 6 KB
Enter the output file name or Decompressed File Name: output.txt
Decompression completed.
Decompressed File created: output.txt
decompressed file size: 10 KB
```

## Algorithm Overview

**Huffman Coding** is a lossless data compression algorithm that:
- Assigns variable-length codes to characters
- More frequent characters get shorter codes
- Less frequent characters get longer codes
- Guarantees optimal prefix-free coding

## Requirements

- C++11 or later
- Standard C++ library

## Components

### FrequencyCounter
Analyzes input files and counts the occurrence of each byte value (0-255).

### HuffmanNode
Represents nodes in the Huffman tree, supporting tree construction and code generation.

### HuffmanCompressor
Handles the compression and decompression operations using the generated Huffman codes.

### SimpleMap
Maps characters to their corresponding Huffman binary codes.

### myQueue
Priority queue implementation used for building the Huffman tree efficiently.

## License

This project is for educational purposes.

## Author
Muhammad Inaam ul haq
Master's Program Project - 2026
