#include <iostream>
#include <vector>
#include <deque>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

vector<vector<int>> levelOrder(TreeNode *root) {
    vector<vector<int>> res;
    if (!root) {
        return res;
    }
    deque<TreeNode*> cur;
    deque<TreeNode*> next;
    int level = 0;
    cur.push_back(root);
    res.push_back(vector<int>());
    while (!cur.empty()) {
        TreeNode *temp = cur.front();
        cur.pop_front();
        if (temp->left) {
            next.push_back(temp->left);
        }
        if (temp->right) {
            next.push_back(temp->right);
        }
        res[level].push_back(temp->val);
        if (cur.empty() && !next.empty()) {
            level++;
            res.push_back(vector<int>());
            swap(cur, next);
        }
    }
    return res;
}

vector<vector<int>> levelOrderDFS(TreeNode *root) {
    vector<vector<int>> res;
    if (!root) {
        return res;
    }
    helper(root, res, 0);
    return res;
}

void helper(TreeNode* root, vector<vector<int>>& res, int level) {
    if (!root) {
        return;
    }
    if (level == res.size()) {
        res.push_back(vector<int>());
    }
    res[level].push_back(root->val);
    helper(root->left, res, level + 1);
    helper(root->right, res, level + 1);
}