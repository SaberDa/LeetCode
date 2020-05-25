#include <iostream>
#include <algorithm>
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

vector<vector<int>> levelOrderBottom(TreeNode *root) {
    vector<vector<int>> res;
    if (!root) {
        return res;
    }
    deque<TreeNode*> cur;
    deque<TreeNode*> next;
    cur.push_back(root);
    vector<int> temp;
    while (!cur.empty()) {
        auto node = cur.front();
        cur.pop_front();
        temp.push_back(node->val);
        if (node->left) {
            next.push_back(node->left);
        }
        if (node->right) {
            next.push_back(node->right);
        }
        if (cur.empty()) {
            res.push_back(temp);
            temp.clear();
            swap(cur, next);
        }
    }
    reverse(res.begin(), res.end());
    return res;
}