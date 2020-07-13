#include <iostream>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left, *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

void DFS(TreeNode *node, int& sum) {
    if (!node) return;
    DFS(node->right, sum);
    node->val += sum;
    sum = node->val;
    DFS(node->left, sum);
}

TreeNode* bstToGst(TreeNode* root) {
    int sum = 0;
    DFS(root, sum);
    return root;
}