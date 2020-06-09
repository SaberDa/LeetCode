#include <iostream>
#include <queue>

using namespace std;

struct TreeNode{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {} 
};

TreeNode* invertTree(TreeNode* root) {
    // if (!root) {
    //     return root;
    // }
    // auto left = invertTree(root->right);
    // auto right = invertTree(root->left);
    // root->left = left;
    // root->right = right;
    // return root;

    queue<TreeNode*> q;
    if (root) q.push(root);
    while (!q.empty()) {
        TreeNode *node = q.front();
        q.pop();
        if (node->left) q.push(node->left);
        if (node->right) q.push(node->right);
        swap(node->right, node->left);
    }
    return root;
}