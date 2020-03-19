#include <iostream>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    bool isPalindrome(ListNode *head) {
        if (!head || !head->next) {
            return true;
        }
        ListNode *slow(head), *fast(head->next);
        while (fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
        }

        ListNode *newHead = slow->next;
        slow->next = NULL;

        ListNode *next(0), *pre(0);
        while (newHead) {
            next = newHead->next;
            newHead->next = pre;
            pre = newHead;
            newHead = next;
        }
        newHead = pre;

        while (newHead) {
            if (head->val != newHead->val) {
                return false;
            }
            head = head->next;
            newHead = newHead->next;
        }

        return true;
    }
};