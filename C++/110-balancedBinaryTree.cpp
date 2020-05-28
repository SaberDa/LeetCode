#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

bool isBalanced(TreeNode *root) {
    int height = 0;
    if (!root) {
        return true;
    }
    return helper(root, height);
}

bool helper(TreeNode *root, int& height) {
    if (!root) {
        height = 0;
        return true;
    }
    int left = 0;
    int right = 0;
    if (!helper(root->left, left)) {
        return false;
    }
    if (!helper(root->right, right)) {
        return false;
    }
    if (abs(left - right) > 1) {
        return false;
    }
    height = max(left, right) + 1;
    return true;
}