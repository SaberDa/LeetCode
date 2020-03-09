#include <iostream>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public :
    ListNode* rotateRight(ListNode* head, int k) {
        if (head == NULL || head->next == NULL) {
            return head;
        }
        int length = 0;
        ListNode *next = head;
        while (next) {
            next = next->next;
            length++;
        }
        k = k % length;
        if (k == 0) {
            return head;
        }
        ListNode *right(head), *left(head);
        while (k--) {
            right = right->next;
        }
        while (right->next) {
            right = right->next;
            left = left->next;
        }
        ListNode *res = left->next;
        left->next = NULL;
        right->next = head;
        return res;
    }
};