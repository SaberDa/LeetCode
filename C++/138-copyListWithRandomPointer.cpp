#include <iostream>
#include <unordered_map>

using namespace std;

class Node {
public:
    int val;
    Node *next;
    Node *random;

    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};

class Solution {
public:
    Node* copyRandomLIst(Node* head) {
        // solution 1
        // use hash map
        if (!head) {
            return head;
        }
        unordered_map<Node*, Node*> newMap;
        Node *dummy = new Node(0);
        Node *cur = dummy;
        while (head) {
            Node *temp = NULL;
            auto it = newMap.find(head);
            if (it == newMap.end()) {
                temp = new Node(head->val);
                newMap[head] = temp;
            } else {
                temp = it->second;
            }
            if (head->random != NULL) {
                auto iter = newMap.find(head->random);
                if (iter == newMap.end()) {
                    Node *tempp = new Node(head->random->val);
                    newMap[head->random] = tempp;
                    temp->random = tempp;
                } else {
                    temp->random = iter->second;
                }
            }
            head = head->next;
            cur->next = temp;
            cur = cur->next;
        }
        return dummy->next;
    }
};