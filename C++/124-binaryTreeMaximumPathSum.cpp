#include <iostream>
#include <climits>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

int helper(TreeNode *root, int &maxSum) {
    if (!root) {
        return 0;
    }
    int left = 0;
    int right = 0;
    if (root->left) {
        left = helper(root->left, maxSum);
    }
    if (root->right) {
        right = helper(root->right, maxSum);
    }
    int temp = max(root->val, root->val + max(left, right));
    maxSum = max(maxSum, max(root->val + left + right, temp));
    return temp;
}

int maxPathSum(TreeNode *root) {
    int maxSum = INT_MIN;
    helper(root, maxSum);
    return maxSum;
}