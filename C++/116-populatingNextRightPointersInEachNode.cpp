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

Node* connect(Node* root) {
    if (!root) {
        return NULL;
    }
    deque<Node*> cur;
    deque<Node*> next;
    cur.push_back(root);
    while (!cur.empty()) {
        Node *temp = cur.front();
        cur.pop_front();
        temp->next = cur.empty() ? NULL : cur.front();
        if (temp->left) {
            next.push_back(temp->left);
        }
        if (temp->right) {
            next.push_back(temp->right);
        }
        if (cur.empty()) {
            swap(cur, next);
        }
    }
    return root;
}