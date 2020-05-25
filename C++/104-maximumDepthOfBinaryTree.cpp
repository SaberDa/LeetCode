#include <iostream>
#include <algorithm>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

void helper(TreeNode* root, int &depth, int cur) {
    if (cur > depth) {
        depth = cur;
    }
    if (root->left) {
        helper(root->left, depth, cur + 1);
    }
    if (root->right) {
        helper(root->right, depth, cur + 1);
    }
}

int maxDepth(TreeNode* root) {
    if (!root) {
        return 0;
    }
    int depth = 1;
    helper(root, depth, 1);
    return depth;
}

int maxDepth(TreeNode *root) {
    if (!root) {
        return 0;
    }
    return max(maxDepth(root->left), maxDepth(root->right)) + 1;
}