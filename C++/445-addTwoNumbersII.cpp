#include <iostream>
#include <vector>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        if (!l1 && l2) {
            return l2;
        } else if (l1 && !l2) {
            return l1;
        } else if (!l1 && !l2) {
            return NULL;
        }
        ListNode *p = l1;
        int sum1(0), sum2(0);
        while (p) {
            sum1 += 1;
            p = p->next;
        }
        p = l2;
        while (p) {
            sum2 += 1;
            p = p->next;
        }
        ListNode *big = sum1 > sum2 ? l1 : l2;
        ListNode *small = sum1 > sum2 ? l2 : l1;
        vector<int> ans(max(sum1, sum2));
        int cur = 0;
        while (big && small) {
            if (cur < abs(sum1-sum2)) {
                ans[cur++] = big->val;
                big = big->next;
            } else {
                ans[cur++] = big->val + small->val;
                big = big->next;
                small = small->next;
            }
        }
        for (int i = ans.size() - 1; i > 0; i--) {
            ans[i-1] += ans[i] / 10;
            ans[i] %= 10;
        }
        if (ans[0] / 10) {
            ans.insert(ans.begin(), ans[0]/10);
            ans[1] %= 10;
        }
        ListNode *res = new ListNode(-1);
        ListNode *head = res;
        for (auto x : ans) {
            res->next = new ListNode(x);
            res = res->next;
        }
        return head->next;
    }
};