#include <iostream>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

bool helper(TreeNode *left, TreeNode *right) {
    if (!left && !right) {
        return true;
    }
    if ((!left && right) || (left && !right)) {
        return false;
    }
    return left->val == right->val && helper(left->left, right->right) && helper(left->right, right->left);
}

bool isSymmetric(TreeNode *root) {
    if (!root) {
        return true;
    }
    return helper(root->left, root->right);
}