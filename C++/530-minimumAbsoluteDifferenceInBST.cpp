#include <iostream>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left, *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

int DFS(TreeNode *node, int val, int res) {
    if (!node) return res;
    res = min(res, abs(node->val - val));
    if (node->val <= val) return DFS(node->right, val, res);
    else return DFS(node->left, val, res); 
}

int getMinimumDifference(TreeNode* root) {
    if (!root) return INT_MAX;
    int res = min(DFS(root->left, root->val, INT_MAX), DFS(root->right, root->val, INT_MAX));
    return min({res, getMinimumDifference(root->left), getMinimumDifference(root->right)});
}