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
    vector<ListNode*> splitListToParts(ListNode *root, int k) {
        vector<ListNode*> res;
        int length = 0;
        ListNode *p(root);
        while (p) {
            p = p->next;
            length++;
        }
        int part = length / k;
        int remainder = length % k; 
        ListNode *head = new ListNode(0);
        ListNode *cur = head;
        ListNode *fakeRoot;
        ListNode *pre(root);
        while (k--) {
            cur->next = pre;
            for (int i = 0; i < part; i++) {
                cur = cur->next;
            }
            if (remainder) {
                cur = cur->next;
                remainder--;
            }
            fakeRoot = cur->next;
            cur->next = NULL;
            res.push_back(pre);
            pre = fakeRoot;
            cur = head;
        }

        return res;
    }
};