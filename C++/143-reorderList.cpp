#include <iostream>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    void reorderList(ListNode *head) {
        if (head == NULL || head->next == NULL) {
            return;
        }
        ListNode *slow(head), *fast(head);
        ListNode *pre = new ListNode(0);
        pre->next = slow;
        while (fast && fast->next) {
            pre = pre->next;
            slow = slow->next;
            fast = fast->next->next;
        }
        if (fast) {
            pre = pre->next;
            slow = slow->next;
        }
        pre->next = NULL;
        ListNode *cur;
        ListNode *next;
        pre = NULL;
        cur = slow;
        while (cur) {
            next = cur->next;
            cur->next = pre;
            pre = cur;
            cur = next;
        }
        ListNode *h1(head), *h2(pre);
        ListNode *temp1, *temp2;
        while (h1 && h2) {
            temp1 = h1->next;
            temp2 = h2->next;
            h1->next = h2;
            h2->next = temp1;
            h1 = temp1;
            h2 = temp2;
        }
    }
};