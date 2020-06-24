#include <iostream>
#include <vector>
#include <stack>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *node) : val(x), next(node) {}
};

vector<int> nextLargerNode(ListNode *head) {
    vector<int> res;
    stack<pair<int, int>> s;
    for (int i = 0; head; head = head->next) {
        while (s.size() && head->val > s.top().first) {
            res[s.top().second] = head->val;
            s.pop();
        }
        s.push({head->val, i++});
        res.push_back(0);
    }
    return res;
}