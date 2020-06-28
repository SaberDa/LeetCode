#include <iostream>
#include <vector>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode* next) : val(x), next(nullptr) {}
};

ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
    if (!headA || !headB) return NULL;
    ListNode *tail = headA;
    while (tail->next) tail = tail->next;
    tail->next = headA;

    ListNode *slow = headB, *fast = headB;
    bool flag = false;
    while (fast && fast->next) {
        slow = slow->next;
        fast = fast->next->next;
        if (slow == fast) {
            flag = true;
            break;
        }
    }
    if (flag) {
        slow = headB;
        while (slow != fast) {
            slow = slow->next;
            fast = fast->next;
        }
        tail->next = NULL;
        return slow;
    }
    tail->next = NULL;
    return NULL;
}