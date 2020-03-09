#include <iostream>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val, next(NULL) {}
};

class Solition {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        if (head == NULL || head->next == NULL) {
            return head;
        }
        ListNode *dummy = new ListNode(-1);
        dummy->next = head;
        ListNode *p1, *p2;
        p1 = head;
        p2 = dummy;
        while (p1->next != NULL) {
            if (p1->val != p1->next->val) {
                p2 = p1;
                p1 = p1->next;
                if (p1 && p1->next && p1->val != p1->next->val) {
                    p2->next = p1;
                }
            } else if (p1->val == p1->next->val) {
                ListNode *temp = p1;
                while (temp->val == temp->next->val) {
                    temp = temp->next;
                    if (temp->next == NULL) {
                        p2->next = temp;
                        return dummy->next;
                    }
                    p1 = temp;
                    p2->next = p1;
                }
            }
        }
        return dummy->next;
    }
};