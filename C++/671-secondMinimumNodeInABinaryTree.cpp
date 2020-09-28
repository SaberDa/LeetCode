#include <iostream>
#include <vector>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left, *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

int DFS(TreeNode *node, int val) {
    if (!node) return -1;
    if (node->val != val) return node->val;
    int l = DFS(node->left, val);
    int r = DFS(node->right, val);
    return (l == -1 || r == -1) ? max(l, r) : min(l, r);
}

int findSecondMinimumValue(TreeNode *root) {
    return DFS(root, root->val);
}