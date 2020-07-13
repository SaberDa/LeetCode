#include <iostream>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left, *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

pair<int, int> DFS(TreeNode *node, int& res) {
    if (!node) return {0, 0};
    int iL = 1, dL = 1;
    int iR = 1, dR = 1;
    auto l = DFS(node->left, res);
    auto r = DFS(node->right, res);
    if (node->left && node->left->val == node->val + 1) iL += l.first;
    if (node->left && node->left->val == node->val - 1) dL += l.second;
    if (node->right && node->right->val == node->val + 1) iR += r.first;
    if (node->right && node->right->val == node->val - 1) dR += r.second;
    res = max({res, iL + dR - 1, dL + iR - 1});
    return {max(iL, iR), max(dL, dR)};
}

int longestConsecutive(TreeNode* root) {
    int res = 0;
    DFS(root, res);
    return res;
}