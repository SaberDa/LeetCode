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

long int preV = -2147483648;

bool isValidBST(TreeNode *root) {
    if (root == nullptr) {
        return true;
    }
    bool isLeftValid = isValidBST(root->left);
    if (root->val <= preV) {
        return false;
    }
    preV = root->val;
    bool isRightValid = isValidBST(root->right);
    return isLeftValid && isRightValid;
}