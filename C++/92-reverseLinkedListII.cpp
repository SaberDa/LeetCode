#include <iostream>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
private:
    ListNode* reverseBetweenHelper(ListNode* head, ListNode* newHead) {
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
    ListNode* reverseBetween(ListNode* head, int m, int n) {
        if (head == NULL || head->next == NULL) {
            return head;
        }
        ListNode *dummy = new ListNode(0);
        dummy->next = head;
        ListNode *first(dummy), *last(dummy);
        int count = 0;
        ListNode *prev;
        while (count < m) {
            prev = last;
            last = last->next;
            first = first->next;
            count++;
        }
        while (count < n) {
            first = first->next;
            count++;
        }
        prev->next = reverseBetweenHelper(last, first->next);
        return dummy->next;
    }
};