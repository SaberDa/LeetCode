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

// TreeNode* DFS(TreeNode* node, vector<int>& temp) {
//     if (!node) return NULL;
//     if (!node->left && !node->right) {
//         temp.push_back(node->val);
//         return NULL;
//     }
//     node->left = DFS(node->left, temp);
//     node->right = DFS(node->right, temp);
//     return node;
// }

// vector<vector<int>> findLeaves(TreeNode* root) {
//     vector<vector<int>> res;
//     while (root) {
//         vector<int> temp;
//         root = DFS(root, temp);
//         res.push_back(temp);
//     }
//     return res;
// }

int DFS(vector<vector<int>>& res, TreeNode* node) {
    if (!node) return 0;
    int leftHeight = DFS(res, node->left);
    int rightHeight = DFS(res, node->right);
    int idx = max(leftHeight, rightHeight);
    if (idx == res.size()) res.push_back(vector<int>());
    res[idx].push_back(node->val);
    return idx + 1;
}

vector<vector<int>> findLeaves(TreeNode* root) {
    vector<vector<int>> res;
    DFS(res, root);
    return res;
}