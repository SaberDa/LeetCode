#include <iostream>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left, *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

int DFS(TreeNode *node, int& res) {
    if (!node) return 0;
    int left = DFS(node->left, res);
    int right = DFS(node->right, res);
    res += abs(left - right);
    return node->val + left + right;
}

int findTilt(TreeNode* root) {
    int res = 0;
    if (!root) return 0;
    DFS(root, res);
    return res;
}