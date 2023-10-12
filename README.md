# Huffman Compression Algorithm

This C++ program implements the Huffman coding algorithm for lossless data compression. Huffman coding is widely used in data compression and is a fundamental technique for reducing the size of data for storage and transmission. This README will guide you through the structure and usage of this code.

## Table of Contents
- [Introduction](#introduction)
- [Code Structure](#code-structure)
- [Usage](#usage)
- [File Input](#file-input)
- [Sample Output](#sample-output)
- [License](#license)

## Introduction

Huffman coding is a variable-length prefix coding algorithm used for lossless data compression. The core idea is to assign shorter codes to more frequent characters, resulting in a more efficient representation of the data.

This program includes:
- The construction of a Huffman tree based on the input text's character frequencies.
- Encoding the input text using the Huffman tree.
- Decoding the encoded text back to its original form.

## Code Structure

The code is organized into the following main components:

- `Node` Structure: Represents elements of the Huffman tree, including pointers to left and right children, character value, and frequency.
- `Comparator` Structure: Compares two `Node` objects for use in the priority queue when building the Huffman tree.
- `createHuffmanTree()`: Constructs the Huffman tree based on the input text.
- `decode()`: Decodes encoded text using the constructed Huffman tree.
- `encodeNode()`: Recursively generates the Huffman codes for each character.
- Input methods: Reads input either from the console or a text file.
- Main function: Manages user interaction and demonstrates the Huffman encoding process.

## Usage

Compile the code using a C++ compiler 

```shell
g++ main.cpp tree.h coding.h decoding.h -o huffman
```

## File Input

To read data from a file, follow these steps:

- Create a text file containing the data you want to compress.
- Place the text file in the same directory as the executable.
- When prompted for an input source, choose option 2 and enter the name of the text file

## Sample output

The program will display the Huffman coding table, the encoded text, and the decoded text.

Sample output:

```yaml
Huffman Coding
-------------------------------------------------------------------
Choose 0 to exit the program
Choose 1 to input data from the console
Choose 2 to read data from a file
-------------------------------------------------------------------
Option choice: 1
Enter text:
This is a sample input text.

Huffman Coding Table:

  : 0
T : 10
a : 1100
e : 1101
h : 11100
i : 11101
m : 11110
n : 11111
p : 1000
s : 1001
t : 1010
u : 1011
x : 111110

Text after encoding:
101011001100111001111011101111111011100011110110011100011111011010100011000110101101011101111000101

Text after decoding:
This is a sample input text.
```

## License

This Huffman Compression Algorithm is open-source software licensed under the MIT License. Feel free to use, modify, and distribute it as needed.
