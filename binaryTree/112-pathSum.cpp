#include <iostream>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left, *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

bool hasPathSum(TreeNode* root, int sum) {
    if (!root) return false;
    int newSum = sum - root->val;
    if (!root->left && !root->right) return newSum == 0;
    return hasPathSum(root->left, newSum) || hasPathSum(root->right, newSum);
}