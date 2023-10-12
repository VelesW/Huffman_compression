#include "coding.h"

// We create a function that decodes the encoded text based on the constructed tree.
string decode(Node* root, string encoded) {
    string decoded = "";
    Node* current_node = root; // Pointer to the currently checked leaf
    for (char c : encoded) {
        if (c == '0') {
            if (current_node->left->isLeaf()) {
                decoded += current_node->left->character;
                current_node = root;
            }
            else {
                current_node = current_node->left;
            }
        }
        else {
            if (current_node->right->isLeaf()) {
                decoded += current_node->right->character;
                current_node = root;
            }
            else {
                current_node = current_node->right;
            }
        }
    }
    return decoded; // Finally, we return the decoded text
}
