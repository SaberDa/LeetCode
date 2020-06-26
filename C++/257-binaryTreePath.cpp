#include <iostream>
#include <vector>
#include <string>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

void DFS(vector<string>& res, TreeNode* node, string str) {
    if (!node) return;
    if (!node->left && !node->right) {
        res.push_back(str + to_string(node->val));
        return;
    }
    DFS(res, node->left, str + to_string(node->val) + "->");
    DFS(res, node->right, str + to_string(node->val) + "->");
}

vector<string> binaryTreePaths(TreeNode* root) {
    vector<string> res;
    if (!root) return res;
    DFS(res, root, "");
    return res;
}