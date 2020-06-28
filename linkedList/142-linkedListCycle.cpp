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

ListNode *detectCycle(ListNode *head) {
    if (!head || !head->next) return NULL;
    ListNode *slow = head, *fast = head;
    bool flag = false;
    while (fast && fast->next && fast->next->next) {
        slow = slow->next;
        fast = fast->next->next;
        if (slow == fast) {
            flag = true;
            break;
        }
    }
    if (!flag) return NULL;
    slow = head;
    while (slow != fast) {
        slow = slow->next;
        fast = fast->next;
    }
    return slow;
}