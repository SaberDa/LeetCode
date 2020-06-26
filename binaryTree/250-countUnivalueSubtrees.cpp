#include <iostream>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left, *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

bool BFS(TreeNode *node, int val, int& res) {
    if (!node) return true;
    res++;
    if (node->val != val) return false;
    return BFS(node->left, val, res) && BFS(node->right, val, res);
}

int countUnivalSubtrees(TreeNode* root) {
    if (!root) return 0;
    int res = 0;
    if (BFS(root, root->val, res)) return res;
    return countUnivalSubtrees(root->left) + countUnivalSubtrees(root->right);
}
