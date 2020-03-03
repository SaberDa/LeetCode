#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

TreeNode* finder(vector<int>& preorder, int pStart, int pEnd, vector<int>& inorder, int iStart, int iEnd) {
    if (pStart > pEnd) return NULL;
    TreeNode *root = new TreeNode(preorder[pStart]);
    int i = find(inorder.begin(), inorder.end(), preorder[pStart]) - inorder.begin();
    root->left = finder(preorder, pStart+1, pStart+i-iStart, inorder, iStart, i-1);
    root->right = finder(preorder, pStart+i-iStart+1, pEnd, inorder, i+1, iEnd);
    cout << root->val << endl;
    return root;
}

TreeNode * buildTree(vector<int>& preorder, vector<int>& inorder) {
    return finder(preorder, 0, preorder.size()-1, inorder, 0, inorder.size()-1);
}

int main() {

    vector<int> preorder = { 3,9,20,15,7 };
    vector<int> inorder = { 9,3,15,20,7 };

    buildTree(preorder, inorder);
    

    return 0;
}