#include <iostream>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    TreeNode* sortedListToBST(ListNode* head) {
        if (!head) {
            return NULL;
        }
        if (!head->next) {
            return new TreeNode(head->val);
        }
        ListNode *slow(head);
        ListNode *fast(head->next);
        ListNode *pre = new ListNode(0);
        pre->next = slow;
        while (fast) {
            slow = slow->next;
            pre = pre->next;
            fast = fast->next ? fast->next->next : NULL;
        }
        TreeNode *root = new TreeNode(slow->val);
        pre->next = NULL;
        root->left = sortedListToBST(head);
        root->right = sortedListToBST(slow->next);
        return root;
    }
};