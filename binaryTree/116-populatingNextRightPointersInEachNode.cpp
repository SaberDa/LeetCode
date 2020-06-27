#include <iostream>
#include <deque>

using namespace std;

class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};

Node *connect(Node *root) {
    if (!root) return NULL;
    deque<Node*> cur, next;
    cur.push_back(root);
    while (!cur.empty()) {
        Node *node = cur.front();
        cur.pop_front();
        node->next = cur.empty() ? NULL : cur.front();
        if (node->left) next.push_back(node->left);
        if (node->right) next.push_back(node->right);
        if (cur.empty()) swap(cur, next);
    }
    return root;
}