#include <vector>

using namespace std;

class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* parent;
};

Node* inorderSuccessor(Node* node) {
    if (node->right) {
        node = node->right;
        while (node->left) node = node->left;
        return node;
    } else {
        while (node->parent) {
            if (node == node->parent->right) node = node->parent;
            else return node->parent;
        }
    }
    return NULL;
}