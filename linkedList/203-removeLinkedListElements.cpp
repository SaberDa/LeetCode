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

ListNode* removeElements(ListNode* head, int val) {
    if (!head) return NULL;
    while (head && head->val == val) head = head->next;
    if (!head) return head;
    ListNode* temp = head;
    while (temp->next) {
        if (temp->next->val == val) temp->next = temp->next->next;
        else temp = temp->next;
    }
    return head;
}