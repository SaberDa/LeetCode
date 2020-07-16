#include <iostream>
#include <vector>
#include <string>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left, *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

int getHeight(TreeNode *node) {
    if (!node) return 0;
    int left = getHeight(node->left);
    int right = getHeight(node->right);
    return max(left, right) + 1;
}

int getWidth(TreeNode *node) {
    if (!node) return 0;
    int left = getWidth(node->left);
    int right = getWidth(node->right);
    return max(left, right) * 2 + 1;
}

void helper(TreeNode *node, vector<vector<string>>& res, int level, int l, int r) {
    if (!node) return;
    int mid = l + (r - l) / 2;
    res[level][mid] = to_string(node->val);
    helper(node->left, res, level + 1, l, mid - 1);
    helper(node->right, res, level + 1, mid + 1, r);
}

vector<vector<string>> printTree(TreeNode* root) {
    if (!root) return vector<vector<string>>();
    int h = getHeight(root);
    int w = getWidth(root);
    vector<vector<string>> res(h, vector<string>(w, ""));
    helper(root, res, 0, 0, w - 1);
    return res;
}