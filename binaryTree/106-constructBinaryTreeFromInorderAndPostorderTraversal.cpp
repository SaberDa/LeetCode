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

TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
    return finder(inorder, 0, inorder.size() - 1, postorder, 0, postorder.size() - 1);
}

TreeNode* finder(vector<int>& inorder, int iStart, int iEnd, vector<int>& postorder, int pStart, int pEnd) {
    if (iStart > iEnd) return NULL;
    TreeNode *node = new TreeNode(postorder[pEnd]);
    int i = find(inorder.begin(), inorder.end(), postorder[pEnd]) - inorder.begin();
    node->left = finder(inorder, iStart, i - 1, postorder, pStart, pStart + i - iStart - 1);
    node->right = finder(inorder, i + 1, iEnd, postorder, pEnd + i - iEnd, pEnd - 1);
    return node;
}