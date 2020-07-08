#include <iostream>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left, *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

void helper(TreeNode *pre, TreeNode *cur) {
    TreeNode *node = cur->left;
    while (node && node->right) node = node->right;
    if (node) node->right = cur->right;
    else cur->left = cur->right;
    if (cur == pre->left) {
        pre->left = cur->left;
    } else {
        pre->right = cur->left;
    }
}

void DFS(TreeNode* pre, TreeNode *cur, int key) {
    if (!cur) return;
    if (cur->val > key) DFS(cur, cur->left, key);
    else if (cur->val < key) DFS(cur, cur->right, key);
    else helper(pre, cur);
}

TreeNode *deleteNode(TreeNode* root, int key) {
    TreeNode *head = new TreeNode(0);
    head->left = root;
    DFS(head, root, key);
    return head->left;
}