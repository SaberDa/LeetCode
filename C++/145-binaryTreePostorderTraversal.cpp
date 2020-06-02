#include <iostream>
#include <stack>
#include <vector>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

vector<int> postorderTraversal(TreeNode* root) {
    vector<int> res;
    if (!root) {
        return res;
    }
    stack<TreeNode*> s;
    TreeNode* cur = root;
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