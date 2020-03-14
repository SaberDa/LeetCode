#include <iostream>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* partition(ListNode* head, int x) {
        ListNode *cur(head);
        ListNode *little = new ListNode(0);
        ListNode *big = new ListNode(0);
        ListNode *res(little);
        ListNode *fakeRes(big);
        while (cur) {
            if (cur->val < x) {
                little->next = cur;
                little = little->next;
            } else {
                big->next = cur;
                big = big->next;
            }
            cur = cur->next;
        }
        big->next = NULL;
        little->next = fakeRes->next;
        return res->next;
    }
};