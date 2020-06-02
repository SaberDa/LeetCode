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

vector<int> preorderTraversal(TreeNode* root) {
    vector<int> res;
    if (!root) {
        return res;
    }
    stack<TreeNode*> s;
    TreeNode *cur = root;
    while (!s.empty() || cur) {
        res.push_back(cur->val);
        if (cur->right) {
            s.push(cur->right);
        }
        if (cur->left) {
            cur = cur->left;
        } else {
            if (s.empty()) {
                break;
            }
            cur = s.top();
            s.pop();
        }
    }
    return res;
}