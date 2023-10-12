#include "tree.h"

// Recursive function encodes elements based on their position in the tree.
void encodeNode(Node* node, string value, map<char, string>* map) {
    if (node == nullptr) { // STOP condition
        return;
    }
    if (node->isLeaf()) {
        cout << node->character << " : " + value << endl;
        map->insert({ node->character, value });
    }
    encodeNode(node->left, value + '0', map);
    encodeNode(node->right, value + '1', map);
}
