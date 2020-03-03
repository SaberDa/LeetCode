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

TreeNode* finder(vector<int>& inorder, int iStart, int iEnd, vector<int>& postorder, int pStart, int pEnd) {
    if (iStart > iEnd) return NULL;
    TreeNode *root = new TreeNode(postorder[pEnd]);
    int i = find(inorder.begin(), inorder.end(), postorder[pEnd]) - inorder.begin();
    root->left = finder(inorder, iStart, i-1, postorder, pStart, pStart+i-iStart-1);
    root->right = finder(inorder, i+1, iEnd, postorder, pEnd+i-iEnd, pEnd-1);
    cout << root->val << endl;
    return root;
}

TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
    return finder(inorder, 0, inorder.size()-1, postorder, 0, postorder.size()-1);
}

int main() {

    vector<int> inorder = { 9,3,15,20,7 };
    vector<int> postorder = { 9,15,7,20,3 };
    
    buildTree(inorder, postorder);

    return 0;
}