#include <iostream>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode *head = new ListNode(0);
        ListNode *cur = head;
        while (l1 && l2) {
            if (l1->val <= l2->val) {
                ListNode *temp = new ListNode(l1->val);
                cur->next = temp;
                cur = temp;
                l1 = l1->next;
            } else {
                ListNode *temp = new ListNode(l2->val);
                cur->next = temp;
                cur = temp;
                l2 = l2->next;
            }
        }
        if (l1) {
            while (l1) {
                ListNode *temp = new ListNode(l1->val);
                cur->next = temp;
                cur = temp;
                l1 = l1->next;
            }
        }
        if (l2) {
            while (l2) {
                ListNode *temp = new ListNode(l2->val);
                cur->next = temp;
                cur = temp;
                l2 = l2->next;
            }
        }
        return head->next;
    }
}