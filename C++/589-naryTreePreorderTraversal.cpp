#include <vector>
#include <deque>

using namespace std;

class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}
    Node(int _val) {
        val = _val;
    }
    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};

vector<int> preorder(Node *root) {
    vector<int> res;
    if (!root) return res;
    deque<Node*> q;
    q.push_back(root);
    while (!q.empty()) {
        auto cur = q.front();
        q.pop_front();
        if (!cur) continue;
        res.push_back(cur->val);
        for (auto it = cur->children.begin(); it != cur->children.end(); it++) {
            q.push_front(*it);
        }
    }
    return res;
}