#include <iostream>
#include <vector>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left, *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    vector<int> res;

    void printLeaves(TreeNode *node) {
        if (!node) return;
        if (!node->left && !node->right) {
            res.push_back(node->val);
        }
        printLeaves(node->left);
        printLeaves(node->right);
    }

    void printLeft(TreeNode *node) {
        if (!node) return;
        if (!node->left && !node->right) return;

        res.push_back(node->val);

        if (node->left) printLeft(node->left);
        else printLeft(node->right);
    }

    void printRight(TreeNode *node) {
        if (!node) return;
        if (!node->left && !node->right) return;

        if (node->right) printRight(node->right);
        else printRight(node->left);

        res.push_back(node->val);
    }

    vector<int> boundaryOfBinaryTree(TreeNode* root) {
        if (!root) return res;
        res.push_back(root->val);
        printLeft(root->left);
        printLeaves(root->left);
        printLeaves(root->right);
        printRight(root->right);
        return res;
    }
};