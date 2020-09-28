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

vector<vector<int>> levelOrder(Node *root) {
    vector<vector<int>> res;
    if (!root) return res;
    deque<Node*> next, cur;
    cur.push_back(root);
    vector<int> temp;
    while (!cur.empty()) {
        Node *node = cur.front();
        cur.pop_front();
        temp.push_back(node->val);
        if (!node->children.empty()) {
            for (auto child : node->children) {
                next.push_back(child);
            }
        }
        if (cur.empty()) {
            res.push_back(temp);
            temp.clear();
            swap(cur, next);
        }
    }
    return res;
}