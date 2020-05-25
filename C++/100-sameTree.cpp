#include <iostream>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};


bool isSameTree(TreeNode *p, TreeNode *q) {
    if (!p && !q) {
        return true;
    }
    if (!p || !q) {
        return false;
    }
    if (p->val != q->val) {
        return false;
    }
    bool left = isSameTree(p->left, q->left);
    bool right = isSameTree(p->right, q->right);
    return left && right;
}