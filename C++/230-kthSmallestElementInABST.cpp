#include <iostream>
#include <stack>

using namespace std;

struct TreeNode{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {} 
};

void helper(TreeNode* root, stack<int>& s) {
    if (!root) return;
    helper(root->right, s);
    s.push(root->val);
    helper(root->left, s);
}

int kthSmallest(TreeNode* root, int k) {
    if (!root) return 0;
    stack<int> s;
    helper(root, s);
    for (int i = 0; i < k - 1; i++) {
        s.pop();
    }
    // while (--k) s.pop();
    return s.top();
}