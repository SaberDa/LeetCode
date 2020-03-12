#include <iostream>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* detectCycle(ListNode *head) {
        if (!head || !head->next) {
            return NULL;
        }
        ListNode *fast(head);
        ListNode *slow(head);
        while (!fast || !fast->next) {
            slow = slow->next;
            fast = fast->next->next;
            if (fast == slow) {
                break;
            }
        }
        slow = head;
        while (slow != fast) {
            slow = slow->next;
            fast = fast->next;
        }
        return slow;
    }
};