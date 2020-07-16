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

bool helper(TreeNode *node, unordered_map<int, int>& mp, int k) {
    if (!node) return false;
    if (mp.count(k - node->val)) return true;
    mp[node->val]++;
    return helper(node->left, mp, k) || helper(node->right, mp, k);
}

bool findTarget(TreeNode* root, int k) {
    if (!root) return false;
    unordered_map<int, int> mp;
    return helper(root, mp, k);
}