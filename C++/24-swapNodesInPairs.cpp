#include <iostream>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode *swapPairs(ListNode *head) {
        if (!head) {
            return head;
        }
        ListNode *prev = head;
        ListNode *temp = head;
        while (temp->next) {
            prev = temp;
            temp = temp->next;
            swap(prev->val, temp->val);
            temp = temp->next;
            if (!temp) {
                break;
            }
        }
        return head;
    }
};