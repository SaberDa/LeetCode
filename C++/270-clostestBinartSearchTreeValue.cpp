#include <iostream>
#include <cmath>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}    
};

int closestValue(TreeNode *root, double target) {
    int res = root->val;
    if (target < res && root->left) {
        int tl = closestValue(root->left, target);
        if (abs(target - tl) < (res - target)) {
            res = tl;
        }
    } else if (target > res && root->right) {
        int rl  = closestValue(root->right, target);
        if (abs(target - rl) < (target - res)) {
            res = rl;
        }
    }
    return res;
}

