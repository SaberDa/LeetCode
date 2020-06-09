#include <iostream>
#include <deque>

using namespace std;

struct TreeNode{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {} 
};

int countNodes(TreeNode* root) {
    if (!root) return 0;
    deque<TreeNode*> cur;
    deque<TreeNode*> next;
    cur.push_back(root);
    int res = 0;
    while (!cur.empty()) {
        TreeNode *node = cur.front();
        cur.pop_front();
        res++;
        if (node->left) next.push_back(node->left);
        if (node->right) next.push_back(node->right);
        if (cur.empty()) {
            swap(cur, next);
        }
    }
    return res;
}