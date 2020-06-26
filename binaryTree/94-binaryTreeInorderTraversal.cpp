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

void DFS(TreeNode *root, vector<int>& res) {
    if (!root) return;
    DFS(root->left, res);
    res.push_back(root->val);
    DFS(root->right, res);
}

vector<int> inorderTraversal(TreeNode *root) {
    vector<int> res;
    if (!root) return res;
    DFS(root, res);
    return res;
}