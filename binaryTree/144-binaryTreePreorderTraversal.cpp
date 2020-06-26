#include <iostream>
#include <stack>
#include <vector>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

void DFS(vector<int>& res, TreeNode* node) {
    if (!node) return;
    res.push_back(node->val);
    DFS(res, node->left);
    DFS(res, node->right);
}

vector<int> preorderTraversal(TreeNode* root) {
    vector<int> res;
    if (!root) return res;
    DFS(res, root);
    return res;
}