#include <iostream>
#include <deque>
#include <vector>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
    vector<vector<int>> res;
    if (!root) return res;
    deque<TreeNode*> cur;
    deque<TreeNode*> next;
    cur.push_back(root);
    int level = 0;
    vector<int> temp;
    while (!cur.empty()) {
        auto it = cur.front();
        cur.pop_front();
        temp.push_back(it->val);
        if (it->left) next.push_back(it->left);
        if (it->right) next.push_back(it->right);
        if (cur.empty()) {
            if (level % 2) reverse(temp.begin(), temp.end());
            level++;
            res.push_back(temp);
            temp.clear();
            swap(cur, next);
        }
    }
    return res;
}