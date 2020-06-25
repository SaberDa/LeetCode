#include <iostream>
#include <vector>
#include <queue>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *node) : val(x), next(node) {}
};

ListNode* mergeKLists(vector<ListNode*>& lists) {
    auto comp = [](ListNode* a, ListNode* b){return a->val > b->val;};
    priority_queue<ListNode*, vector<ListNode*>, decltype(comp)> pq(comp);
    for (auto x : lists) {
        while (x) {
            pq.push(x);
            x = x->next;
        }
    }
    ListNode *node = new ListNode(0);
    ListNode *res = node;
    while (!pq.empty()) {
        node->next = new ListNode(pq.top()->val);
        node = node->next;
        pq.pop();
    }
    return res->next;
}