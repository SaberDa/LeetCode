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

TreeNode* helper(TreeNode* &root, TreeNode* &l, TreeNode* &r) {
    if (!root) {
        return NULL;
    }
    l = helper(root->left, l, r);
    if (l) {
        l->right = root->right;
        root->right = root->left;
        root->left = NULL;
    }
    r = helper(root->right, l, r);
    return r ? r : l ? l : root;
}

void flatten(TreeNode *root) {
    TreeNode *l, *r;
    helper(root, l , r);
}