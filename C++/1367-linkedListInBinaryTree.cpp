#include <iostream>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *node) : val(x), next(node) {}
};

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
    TreeNode() : val(0), left(NULL), right(NULL) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}    
};

bool DFS(ListNode *node, TreeNode *root) {
    if (!node) return true;
    if (!root) return false;
    if (node->val == root->val) 
        return DFS(node->next, root->left) || DFS(node->next, root->right);
    else return false;
}

bool isSubPath(ListNode *head, TreeNode* root) {
    if (!root) return false;
    return DFS(head, root) || isSubPath(head, root->left) || isSubPath(head, root->right);
}