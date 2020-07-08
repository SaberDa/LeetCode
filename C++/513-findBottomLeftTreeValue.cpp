#include <iostream>
#include <deque>
#include <vector>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left, *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

int findBottomLeftValue(TreeNode* root) {
    deque<TreeNode*> cur, next;
    cur.push_back(root);
    vector<int> temp;
    while (!cur.empty()) {
        TreeNode *node = cur.front();
        cur.pop_front();
        temp.push_back(node->val);
        if (node->left) next.push_back(node->left);
        if (node->right) next.push_back(node->right);
        if (cur.empty()) {
            if (!next.empty()) temp.clear(); 
            swap(cur, next);
        }
    }
    return temp[0];
}