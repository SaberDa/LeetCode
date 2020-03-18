#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* merge(ListNode* left, ListNode* right) {
        if (!left) {
            return right;
        }
        if (!right) {
            return left;
        }
        if (left->val > right->val) {
            swap(left, right);
        }
        ListNode* dummy = left;
        ListNode* pre = left;
        left = left->next;
        while (left && right) {
            if (left->val > right->val) {
                pre->next = right;
                right = right->next;
            } else {
                pre->next = left;
                left = left->next;
            }
            pre = pre->next;
        }
        if (left) {
            pre->next = left;
        }
        if (right) {
            pre->next = right;
        }
        return dummy;
    }

    ListNode* sortList(ListNode* head) {
        // not use this
        // ListNode *cur(head);
        // vector<int> res;
        // while (cur) {
        //     res.push_back(cur->val);
        //     cur = cur->next;
        // }
        // cur = head;
        // sort(res.begin(), res.end());
        // for (int i = 0; i < res.size(); i++) {
        //     cur->val = res[i];
        //     cur = cur->next;
        // }
        // return head;
        if (!head || !head->next) {
            return head;
        }
        ListNode *slow(head);
        ListNode *fast(head->next);
        while (fast && fast->next) {
            slow = slow->next;
            fast= fast->next->next;
        }
        ListNode *reHead(slow->next);
        slow->next = NULL;
        return merge(sortList(head), sortList(reHead));
    }
};