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

// Greedy
// res[0] : not rob
// res[1] : rob
vector<int> DFS(TreeNode* node) {
    if (!node) return {0, 0};
    auto left = DFS(node->left);
    auto right = DFS(node->right);
    vector<int> res(2);
    res[0] = max(left[0], left[1]) + max(right[0], right[1]);
    res[1] = node->val + left[0] + right[0];
    return res;
}

int rob(TreeNode* root) {
    auto res = DFS(root);
    return max(res[0], res[1]);
}