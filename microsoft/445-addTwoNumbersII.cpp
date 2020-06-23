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

ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
    if (!l1 && l2) return l2;
    else if (l1 && !l2) return l1;
    else if (!l1 && !l2) return NULL;

    int sum1 = 0, sum2 = 0;
    ListNode *p = l1;
    while (p) sum1++, p = p->next;
    p = l2;
    while (p) sum2++, p = p->next;

    ListNode *big = (sum1 > sum2) ? l1 : l2;
    ListNode *small = (sum1 > sum2) ? l2 : l1;

    int cur = 0;
    vector<int> ans(max(sum1, sum2));

    while (big && small) {
        if (cur < abs(sum1 - sum2)) {
            ans[cur++] = big->val;
            big = big->next;
        } else {
            ans[cur++] = big->val + small->val;
            big = big->next;
            small = small->next;
        }
    }

    for (int i = ans.size() - 1; i > 0; i--) {
        ans[i - 1] += ans[i] / 10;
        ans[i] %= 10;
    }
    if (ans[0] /10) {
        ans.insert(ans.begin(), ans[0] / 10);
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