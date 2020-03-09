#include <iostream>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
private:
    ListNode* reverserKGroupHelper(ListNode *head, ListNode *newHead) {
        ListNode *temp, *last = newHead;
        while (head != last) {
            temp = head;
            head = head->next;
            temp->next = newHead;
            newHead = temp;
        }
        return temp;
    }
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        if (head == NULL || head->next == NULL) {
            return head;
        }
        ListNode *dummy = new ListNode(0);
        dummy->next = head;
        ListNode *first, *last;
        first = head;
        last = head;
        int count = 0;
        ListNode *prev = dummy;
        ListNode *next;
        while (first != NULL) {
            int i = k-1;
            while (first && i) {
                first = first->next;
                i--;
            }
            if (first) {
                next = first->next;
                prev->next = reverserKGroupHelper(last, next);
                prev = last;
                last = next;
                first = next;
            }
        }
        return dummy->next;
    }
};