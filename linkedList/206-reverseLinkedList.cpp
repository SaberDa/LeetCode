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

ListNode* helper(ListNode *head, ListNode* newHead) {
    if (!head) return newHead;
    ListNode *temp = head->next;
    head->next = newHead;
    return helper(temp, head);
}

ListNode* reverseList(ListNode* head) {
    if (!head) return NULL;
    return helper(head, NULL);
}