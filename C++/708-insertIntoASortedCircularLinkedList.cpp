#include <iostram>

class Node {
public:
    int val;
    Node *next;

    Node() {}

    Node(int _val) {
        val = _val;
        next = NULL;
    }

    Node(int _val, Node* _next) {
        val = _val;
        next = _next;
    }
};

Node *insert(Node *head, int insertVal) {
    if (!head) {
        Node *node = new Node(insertVal);
        node->next = node;
        return node;
    }
    Node *node = head;
    do {
        if ((insertVal >= node->val && insertVal <= node->next->val) ||
            (node->val > node->next->val && (insertVal >= node->val || insertVal <= node->next->val)) ||
            (node->next == head)) {
            Node *newNode = new Node(insertVal, node->next);
            node->next = newNode;
            break;        
        }
        node = node->next;
    } while (node != head);
    return head;
}