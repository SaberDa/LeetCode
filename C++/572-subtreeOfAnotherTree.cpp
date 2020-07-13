#include <iostream>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left, *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

bool helper(TreeNode *q, TreeNode *p) {
    if (!q && !p) return true;
    if (!q || !p) return false;
    return (q->val == p->val) && helper(q->left, p->left) && helper(q->right, p->right);
}

bool isSubtree(TreeNode* s, TreeNode* t) {
    if (!s && !t) return true;
    if (!s || !t) return false;
    return helper(s, t) || isSubtree(s->left, t) || isSubtree(s->right, t);
}