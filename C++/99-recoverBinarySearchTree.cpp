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

void DFS(TreeNode *root, TreeNode* &pre, TreeNode* &one, TreeNode* &two) {
    if (!root) {
        return;
    }
    DFS(root->left, pre, one, two);
    if (pre && root->val < pre->val) {
        if (!one) {
            one = pre;
        }
        two = root;
    }
    pre = root;
    DFS(root->right, pre, one, two);
}


void recoverTree(TreeNode *root) {
    TreeNode *pre = NULL, *one = NULL, *two = NULL;
    DFS(root, pre, one, two);
    swap(one->val, two->val);
}