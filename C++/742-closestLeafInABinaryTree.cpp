#include <vector>
#include <iostream>
#include <unordered_map>
#include <deque>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left, *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

void buildGraph(unordered_map<int, vector<int>> &g, unordered_map<int, TreeNode*> &m, TreeNode *root) {
    if (!root) return;
    m[root->val] = root;
    if (root->left) {
        g[root->val].push_back(root->left->val);
        g[root->left->val].push_back(root->val);
        buildGraph(g, m, root->left);
    }
    if (root->right) {
        g[root->val].push_back(root->right->val);
        g[root->right->val].push_back(root->val);
        buildGraph(g, m, root->right);
    }
}

int findClosestLeaf(TreeNode *root, int k) {
    unordered_map<int, vector<int>> g;
    unordered_map<int, TreeNode*> m;
    buildGraph(g, m, root);
    if (g[k].size() == 1 && !m[k]->left && !m[k]->right) return k;
    vector<int> visited(1001, 0);
    deque<int> q;
    q.push_back(k);
    while (!q.empty()) {
        int node = q.front();
        q.pop_front();
        visited[node] = 1;
        bool isEnd = true;
        for (auto neigh : g[node]) {
            if (!visited[neigh]) {
                q.push_back(neigh);
                isEnd = false;
            }
        }
        if (isEnd && !m[node]->left && !m[node]->right) return node;
    }
    return 0;
}

