#include <iostream>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left, *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

void DFS(TreeNode* root, int& sum) {
    if (!root) return;
    DFS(root->right, sum);
    root->val += sum;
    sum = root->val;
    DFS(root->left, sum);
}

TreeNode* convertBST(TreeNode* root) {
    int sum = 0;
    DFS(root, sum);
    return root;
}