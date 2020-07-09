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

TreeNode* str2tree(string s) {
    if (s.empty()) return NULL;
    int i = 0;
    while (i < s.size() && (isdigit(s[i]) || s[i] == '-')) i++;
    TreeNode *node = new TreeNode(stoi(s.substr(0, i)));
    int k = 0;
    for (int j = i; j < s.size(); j++) {
        if (s[j] == '(') k++;
        else if (s[j] == ')') k--;
        if (k == 0) {
            if (!node->left) node->left = str2tree(s.substr(i + 1, j - i - 1));
            else node->right = str2tree(s.substr(i + 1, j - i - 1));
            i = j + 1;
        }
    }
    return node;
}