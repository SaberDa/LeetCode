#include <iostream>
#include <vector>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *node) : val(x), next(node) {}
};

int getDecimalValue(ListNode* head) {
    int res = 0;
    while (head) {

        // res = res * 2 + head->val;
        res <<= 1;
        res |= head->val;
        head = head->next;
    }
    return res;
}