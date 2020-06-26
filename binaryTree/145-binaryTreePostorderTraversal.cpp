#include <iostream>
#include <vector>
#include <stack>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left, *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

void DFS(vector<int>& res, TreeNode* node) {
    if (!node) return;
    DFS(res, node->left);
    DFS(res, node->right);
    res.push_back(node->val);
}

vector<int> postorderTraversal(TreeNode *root) {
    vector<int> res;
    if (!root) return res;
    TreeNode *cur = root;
    stack<TreeNode*> s;
    while (!s.empty() || cur) {
        if (cur) {
            res.push_back(cur->val);
            s.push(cur->left);
            cur = cur->right;
        } else {
            cur = s.top();
            s.pop();
        }
    }
    reverse(res.begin(), res.end());
    return res;
}