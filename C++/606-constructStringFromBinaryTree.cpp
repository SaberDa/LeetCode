#include <iostream>
#include <string>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left, *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

string tree2str(TreeNode* t) {
    if (!t) return "";
    string l = tree2str(t->left);
    string r = tree2str(t->right);
    if (!t->left && !t->right) return to_string(t->val);
    if (!t->right) return to_string(t->val) + "(" + l + ")";
    else return to_string(t->val) + "(" + l + ")" + "(" + r + ")";
}