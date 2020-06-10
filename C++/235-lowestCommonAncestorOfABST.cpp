#include <iostream>

using namespace std;

struct TreeNode{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {} 
};

TreeNode *lowestCommonAncestor(TreeNode* root, TreeNode *p, TreeNode *q) {
    int m = max(p->val, q->val);
    int n = min(p->val, q->val);
    if (root->val <= m && root->val >= n) return root;
    if (root->val > m) return lowestCommonAncestor(root->left, p, q);
    return lowestCommonAncestor(root->right, p, q);
}