#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left, *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

string DFS(TreeNode* node, unordered_map<string, int>& mp, vector<TreeNode*>& res) {
    if (!node) return "";
    string s = to_string(node->val) + "," + DFS(node->left, mp, res) + "," + DFS(node->right, mp, res);
    if (++mp[s] == 2) res.push_back(node);
    return s;
}

vector<TreeNode*> findDuplicateSubtrees(TreeNode* root) {
    vector<TreeNode*> res;
    if (!root) return res;
    unordered_map<string, int> mp;
    DFS(root, mp, res);
    return res;
}