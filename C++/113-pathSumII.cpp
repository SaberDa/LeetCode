#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

void helper(TreeNode *root, vector<vector<int>>& res, vector<int> path, int sum, int target) {
    if (!root) {
        return;
    }
    path.push_back(root->val);
    sum += root->val;
    if (!root->left && !root->right) {
        if (sum == target) {
            res.push_back(path);
        }
        return;
    }
    helper(root->left, res, path, sum, target);
    helper(root->right, res, path, sum, target);
}

void DFS(TreeNode *root, vector<vector<int>>& res, vector<int> path, int sum) {
    if (!root) {
        return;
    }
    path.push_back(root->val);
    sum -= root->val;
    if (!root->left && !root->right) {
        if (sum == 0) {
            res.push_back(path);
        }
        return;
    }
    DFS(root->left, res, path, sum);
    DFS(root->right, res, path, sum);
}

vector<vector<int>> pathSum(TreeNode *root, int sum) {
    vector<vector<int>> res;
    if (!root) {
        return res;
    }
    DFS(root, res, vector<int>(), sum);
    // helper(root, res, vector<int>(), 0, sum);
    return res;
}