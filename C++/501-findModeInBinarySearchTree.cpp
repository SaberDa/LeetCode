#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left, *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

void DFS(TreeNode *node, unordered_map<int, int>& mp) {
    if (!node) return;
    mp[node->val]++;
    DFS(node->left, mp);
    DFS(node->right, mp);
}

vector<int> findMode(TreeNode *root) {
    vector<int> res;
    unordered_map<int, int> mp;
    DFS(root, mp);
    int maxVal = 0;
    for (auto it : mp) {
        if (it.second > maxVal) {
            res.clear();
            res.push_back(it.first);
            maxVal = it.second;
        } else if (it.second == maxVal) {
            res.push_back(it.first);
        }
    }
    return res;
}