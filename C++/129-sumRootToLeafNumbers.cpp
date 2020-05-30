#include <iostream>
#include <string>
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

void DFS(vector<string>& res, TreeNode *root, string path) {
    path += to_string(root->val);
    if (!root->right && !root->left) {
        res.push_back(path);
    }
    if (root->left) {
        DFS(res, root->left, path);
    }
    if (root->right) {
        DFS(res, root->right, path);
    }
}

int sumNumbers(TreeNode *root) {
    vector<string> res;
    if (!root) {
        return 0;
    }
    int sum = 0;
    string path;
    DFS(res, root, path);
    for (auto it : res) {
        sum += stoi(it);
    }
    return sum;
}