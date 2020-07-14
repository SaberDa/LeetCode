#include <iostream>
#include <vector>
#include <deque>
#include <numeric>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left, *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

vector<double> averageOfLevels(TreeNode* root) {
    vector<double> res;
    if (!root) return res;
    deque<TreeNode*> cur, next;
    long long temp = 0;
    int level = 0;
    cur.push_back(root);
    while (!cur.empty()) {
        TreeNode *node = cur.front();
        cur.pop_front();
        temp += node->val;
        level++;
        if (node->left) next.push_back(node->left);
        if (node->right) next.push_back(node->right);
        if (cur.empty()) {
            res.push_back((double)temp / level);
            temp = 0;
            level = 0;
            swap(cur, next);
        }
    }
    return res;
}