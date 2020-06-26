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

ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
    ListNode* node = new ListNode(0);
    ListNode *res = node;
    int carry = 0;
    while (l1 || l2 || carry) {
        int x = l1 ? l1->val : 0;
        int y = l2 ? l2->val : 0;
        ListNode *temp = new ListNode((x + y + carry) % 10);
        node->next = temp;
        node = node->next;
        carry = (x + y + carry) / 10;
        if (l1) l1 = l1->next;
        if (l2) l2 = l2->next;
    }
    return res->next;
}