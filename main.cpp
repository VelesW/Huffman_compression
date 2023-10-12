#include "decoding.h"
#include <fstream>
#include <sstream>

using namespace std;

string readFile();

int main()
{
    // Option selection for inputting text from the user
    cout << "Huffman Coding" << endl;
    cout << "-------------------------------------------------------------------" << endl;
    cout << "Choose 0 to exit the program" << endl;
    cout << "Choose 1 to input data from the console" << endl;
    cout << "Choose 2 to read data from a file" << endl;
    cout << "-------------------------------------------------------------------" << endl;
    cout << "Option choice: ";
    int option;
    cin >> option;

    string line;

    switch (option)
    {
    case 0:
        return 0;

    case 1:
        cout << "Enter text: " << endl;
        getline(cin, line); // Consume newline character
        getline(cin, line);
        break;

    case 2:
        // Reading data from a text file
        line = readFile();
        break;

    default:
        cout << "Invalid command choice" << endl;
    }

    // Create a tree based on the input text
    Node* root = createHuffmanTree(line);

    cout << "\nHuffman Coding Table:\n" << endl;
    map<char, string> encodedValues;
    encodeNode(root, "", &encodedValues);

    // Encode the text based on the created map
    string encodedLine = "";
    for (char c : line) {
        encodedLine += encodedValues[c];
    }
    cout << "\nText after encoding:\n" << encodedLine << endl;

    // Decode the text
    cout << "\nText after decoding:\n" << decode(root, encodedLine) << endl;

    delete root;
    return 0;
}

string readFile()
{
    string file_path = "data.txt";
    cout << "\nEnter the file name (default is data.txt): ";
    cin >> file_path;

    ifstream file;
    file.open(file_path);

    ostringstream stream_content;
    string text;

    if (file.is_open())
    {
        while (getline(file, text))
        {
            stream_content << text;
        }
        file.close();
        text = stream_content.str();
        text.erase(remove(text.begin(), text.end(), '\n'), text.cend());

        return text;
    }
    else
    {
        cout << "Unable to open the file" << endl;
        exit(1);
    }
}
