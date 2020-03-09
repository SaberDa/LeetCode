#include <iostream>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val, next(NULL) {}
};

class Solution {
public:
    ListNode* removeElements(ListNode* head, int val) {
        if (head == NULL) {
            return NULL;
        }
        while (head && head->val == val) {
            head = head->next;
        }
        if (head == NULL) {
            return NULL;
        } else {
            ListNode *p1 = head;
            while (p1->next != NULL) {
                if (p1->next->val == val) {
                    p1->next = p1->next->next;
                } else {
                    p1 = p1->next;
                }
            }
        }
        return head;
    }
};