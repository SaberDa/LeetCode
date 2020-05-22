#include <iostream>
#include <vector>
#include <stack>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
private:
    void inorder(vector<int>& res, TreeNode *root) {
        if (!root) {
            return;
        }
        inorder(res, root->left);
        res.push_back(root->val);
        inorder(res, root->right);
    }
public:
    vector<int> inorderTraversal(TreeNode *root) {
        vector<int> res;
        // inorder(res, root);
        if (!root) {
            return res;
        }
        stack<TreeNode*> st;
        TreeNode *cur = root;
        while (!st.empty() || cur) {
            while (cur->left) {
                st.push(cur);
                cur = cur->left;
            }
            res.push_back(cur->val);
            cur = cur->right ? cur->right : NULL;
            while (!st.empty() && !cur) {
                res.push_back(st.top()->val);
                cur = st.top()->right ? st.top()->right : NULL;
                st.pop();
            }
        }

        return res;
    }
};