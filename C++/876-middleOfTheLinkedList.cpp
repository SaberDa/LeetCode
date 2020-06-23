#include <iostream>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *node) : val(x), next(node) {}
};

ListNode *middleNode(ListNode* head) {
    ListNode *a = head, *b = head;
    while (b && b->next) {
        a = a->next;
        b = b->next->next;
    }
    return a;
}