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

TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
    return finder(inorder, 0, inorder.size() - 1, preorder, 0, preorder.size() - 1);
}

TreeNode *finder(vector<int>& inorder, int iStart, int iEnd, vector<int>& preorder, int pStart, int pEnd) {
    if (pStart > pEnd) return NULL;
    TreeNode *node = new TreeNode(preorder[pStart]);
    int i = find(inorder.begin(), inorder.end(), preorder[pStart]) - inorder.begin();
    node->left = finder(inorder, iStart, i - 1, preorder, pStart + 1, pStart + i - iStart);
    node->right = finder(inorder, i + 1, iEnd, preorder, pStart + i - iStart + 1, pEnd);
    return node;
}