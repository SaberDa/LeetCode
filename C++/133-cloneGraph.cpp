#include <iostream>
#include <vector>
#include <unordered_map>
#include <deque>

using namespace std;

class Node {
public:
    int val;
    vector<Node*> neighbors;
    
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};

Node* cloneGraph(Node* node) {
    if (!node) {
        return NULL;
    }
    unordered_map<Node*, Node*> mp;
    Node *root = new Node(node->val);
    mp[node] = root;
    deque<Node*> cur;
    deque<Node*> next;
    cur.push_back(node);
    while (!cur.empty()) {
        Node *temp = cur.front();
        cur.pop_front();
        for (auto it : temp->neighbors) {
            if (mp.count(it) == 0) {
                Node *copy = new Node(it->val);
                mp[it] = copy;
                next.push_back(it);
            }
            mp[temp]->neighbors.push_back(mp[it]);
        }
        if (cur.empty()) {
            swap(cur, next);
        }
    }
    return root;
}