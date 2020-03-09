#include <iostream>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val, next(NULL) {}
};

class Solution {
private:
    ListNode* reverserListHelper(ListNode* head, ListNode* newHead) {
        if (head == NULL) {
            return newHead;
        }
        ListNode *temp = head->next;
        head->next = newHead;
        return reverserListHelper(temp, head);
    }
public:
    ListNode* reverseList(ListNode* head) {
        if (head == NULL || head->next == NULL) {
            return head;
        }
        // solution 1
        // ListNode *dummy;
        // while (head != NULL) {
        //     ListNode *temp = head->next;
        //     head->next = dummy;
        //     dummy = head;
        //     head = temp;
        // }
        // return dummy;
        // solution 2
        return reverserListHelper(head, NULL);
    }
};