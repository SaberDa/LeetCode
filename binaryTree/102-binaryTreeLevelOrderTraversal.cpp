#include <iostream>
#include <vector>
#include <deque>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left, *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

void DFS(vector<vector<int>>& res, TreeNode *node, int level) {
    if (!node) return;
    if (level == res.size()) res.push_back(vector<int>());
    res[level].push_back(node->val);
    DFS(res, node->left, level + 1);
    DFS(res, node->right, level + 1);
}

vector<vector<int>> levelOrder(TreeNode* root) {
    vector<vector<int>> res;
    if (!root) return res;
    DFS(res, root, 0);
    return res;



    // vector<vector<int>> res;
    // if (!root) return res;
    // deque<TreeNode*> cur, next;
    // cur.push_back(root);
    // vector<int> temp;
    // while (!cur.empty()) {
    //     TreeNode *node = cur.front();
    //     cur.pop_front();
    //     temp.push_back(node->val);
    //     if (node->left) next.push_back(node->left);
    //     if (node->right) next.push_back(node->right);
    //     if (cur.empty()) {
    //         res.push_back(temp);
    //         temp.clear();
    //         swap(cur, next);
    //     }
    // }
    // return res;
}