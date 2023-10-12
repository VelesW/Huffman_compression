#include <iostream>
#include <queue>
#include <string>
#include <map>
#include <vector>
#include <algorithm>

using namespace std;

// We construct a leaf structure, which will be the basic element of the encoding tree.
// In this structure, we define pointers to the left and right child,
// the value of the leaf (frequency or their sum), the character to encode, and the encoded character.
struct Node
{
    Node* left;
    Node* right;
    char character;
    int value;

    Node(char c, int v, Node* l = nullptr, Node* r = nullptr) { // constructor of the structure
        left = l;
        right = r;
        character = c;
        value = v;
    }
    ~Node()
    {
        delete right;
        delete left;
    }
    bool isLeaf() {
        return character != '\0';
    }

};

// We create a structure that will help us create the Huffman encoding tree.
// It will compare two tree leaves.
struct Comparator
{
    bool operator() (Node* a, Node* b) {
        if (a->value != b->value)
            return a->value > b->value;
        if (!a->isLeaf() && b->isLeaf())
            return false;
        if (!b->isLeaf() && a->isLeaf())
            return true;
        if (a->isLeaf() && b->isLeaf())
            return a->character > b->character;
        return true;
    }
};

// Define a method that will create a Huffman coding tree and then return its root.
Node* createHuffmanTree(string line)
{
    map<char, int> counter;
    for (char c : line) {
        if (counter.find(c) == counter.end()) { // if the character is not in the map, add it
            counter[c] = 1;
        }
        else {
            counter[c]++; // if the character is in the map, increase its frequency
        }
    }
    // Unassigned tree elements will be stored in the priority_queue object.
    priority_queue<Node*, vector<Node*>, Comparator> nodes;

    for (auto entry : counter)
    {
        nodes.push(new Node(entry.first, entry.second)); // tree leaves are created based on characters and their frequencies
    }
    Node* root{}; // root of the resulting tree
    while (nodes.size() > 1) {
        Node* n1 = nodes.top();
        nodes.pop();
        Node* n2 = nodes.top();
        nodes.pop();
        if (n1->value == n2->value && !n1->isLeaf())
        {
            Node* temp = n1;
            n1 = n2;
            n2 = temp;
        }
        root = new Node('\0', n1->value + n2->value, n1, n2);
        nodes.push(root);
    }
    return root;
}
