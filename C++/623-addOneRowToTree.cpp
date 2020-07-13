#include <iostream>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left, *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

void helper(TreeNode *node, int v, int d, int level) {
    if (!node) return;
    if (d == level) {
        TreeNode *oldLeft = node->left;
        node->left = new TreeNode(v);
        node->left->left = oldLeft;

        TreeNode *oldRight = node->right;
        node->right = new TreeNode(v);
        node->right->right = oldRight;
    }
    helper(node->left, v, d, level + 1);
    helper(node->right, v, d, level + 1);
}

TreeNode* addOneRow(TreeNode* root, int v, int d) {
    if (!root) return NULL;
    if (d == 1) {
        TreeNode *newRoot = new TreeNode(v);
        newRoot->left = root;
        return newRoot;
    }
    helper(root, v, d, 2);
    return root;
}