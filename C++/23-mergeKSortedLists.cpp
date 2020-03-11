#include <iostream>
#include <vector>
#include <queue>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
private:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode *head = new ListNode(0);
        ListNode *cur = head;
        while (l1 && l2) {
            if (l1->val <= l2->val) {
                cur->next = l1;
                l1 = l1->next;
            } else {
                cur->next = l2;
                l2 = l2->next;
            }
            cur = cur->next;
        }
        cur->next = l1 ? l1 : l2;
        return head->next;
    }
public:
    // solution 1
    // use the 21 function
    // ListNode* mergeKLists(vector<ListNode*>& lists) {
    //     ListNode *res;
    //     if (lists.empty()) {
    //         return res;
    //     } else {
    //         res = lists[0];
    //     }
    //     for (int i = 1; i < lists.size(); i++) {
    //         res = mergeTwoLists(res, lists[i]);
    //     }
    //     return res;
    // }

    // solution 2
    // use priority_queue
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        auto comp = [](ListNode* a, ListNode* b) {return a->val > b->val;};
        priority_queue<ListNode*, vector<ListNode*>, decltype(comp)>pq(comp);
        for (auto x : lists) {
            while (x) {
                pq.push(x);
                x = x->next;
            }
        }
        ListNode *head = new ListNode(0);
        ListNode *cur = head;
        while(!pq.empty()) {
            cur->next = pq.top();
            cur = cur->next;
            pq.top()->next = NULL;
            pq.pop();
        }
        return head->next;
    }
};