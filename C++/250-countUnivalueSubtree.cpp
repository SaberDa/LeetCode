#include <iostream>
#include <unordered_map>

using namespace std;

struct TreeNode{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {} 
};

bool helper(TreeNode* root, int val, int& res) {
    if (!root) return true;
    res++;
    if (root->val != val) return false;
    return helper(root->left, val, res) && helper(root->right, val, res);
}

int countUnivalSubtrees(TreeNode* root) {
    if (!root) return 0;
    int res = 0;
    if (helper(root, root->val, res)) return res;
    return countUnivalSubtrees(root->left) + countUnivalSubtrees(root->right);
}