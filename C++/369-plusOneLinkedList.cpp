#include <iostream>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
private:
    ListNode* reverse(ListNode* head) {
        ListNode* pre(NULL), *cur(head), *next;
        while (cur) {
            next = cur->next;
            cur->next = pre;
            pre = cur;
            cur = next;
        }
        return pre;
    }
public:
    ListNode* plusOne(ListNode* head) {
        ListNode *dummy = reverse(head);
        ListNode *temp = dummy;
        while (dummy->val + 1 == 10) {
            dummy->val = 0;
            if (!dummy->next) {
                dummy->next = new ListNode(0);
            }
            dummy = dummy->next;
        }
        dummy->val += 1;
        return reverse(temp);
    }
};