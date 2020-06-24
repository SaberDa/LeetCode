#include <iostream>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *node) : val(x), next(node) {}
};

ListNode* deleteNodes(ListNode* head, int m, int n) {
    ListNode *l = head, *r = head;
    while (r) {
        int c = 1;
        while (r && c++ < m) r = r->next;
        if (!r) break;
        l = r->next;
        c = 0;
        while (l && c++ < n) l = l->next;
        r->next = l;
        if (r) r = r->next;
    }
    return head;
}