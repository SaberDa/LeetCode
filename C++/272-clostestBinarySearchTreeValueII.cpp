#include <iostream>
#include <cmath>
#include <vector>
#include <queue>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}    
};

struct compare {
    bool operator() (const pair<int, double>& l, const pair<int, double>& r) {
        return abs(l.first - l.second) < abs(r.first - r.second);
    }
};

void DFS(TreeNode *root, priority_queue<pair<int, double>, vector<pair<int, double>>, compare>& que, double target, int k) {
    if (!root) {
        return;
    }
    que.push({root->val, target});
    if (que.size() > k) {
        que.pop();
    }
    DFS(root->left, que, target, k);
    DFS(root->right, que, target, k);
}

vector<int> closestKValues(TreeNode *root, double target, int k) {
    priority_queue<pair<int, double>, vector<pair<int, double>>, compare> que;
    DFS(root, que, target, k);
    vector<int> res;
    while (!que.empty()) {
        res.push_back(que.top().first);
        que.pop();
    }
    return res;
}