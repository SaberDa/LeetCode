#include <iostream>
#include <list>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val, next(NULL) {}
};


int main() {
    ListNode* head;

    int n = 2;

    if (head == NULL) {
        return 0;
    }

    ListNode* slow(head);
    ListNode* fast(head);
    while (n) {
        fast = fast->next;
        n--;
    }
    if (!fast) {
        return head->next;
    }
    while (fast->next) {
        slow = slow->next;
        fast = fast->next;
    }
    slow->next = slow->next->next;



    return 0;
}