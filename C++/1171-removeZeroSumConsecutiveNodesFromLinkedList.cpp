#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *node) : val(x), next(node) {}
};


ListNode* removeZeroSumSublists(ListNode* head) {
    ListNode *dummy = new ListNode(0);
    dummy->next = head;
    unordered_map<int, ListNode*> mp;
    mp[0] = dummy;
    int sum = 0;
    while (head) {
        sum += head->val;
        if (mp.count(sum)) {
            ListNode *prev = mp[sum];
            ListNode *start = prev;
            int temp = sum;
            while (prev != head) {
                prev = prev->next;
                temp += prev->val;
                if (prev != head) mp.erase(temp);
            }
            start->next = prev->next;
        } else mp[sum] = head;
        head = head->next;
    }
    return dummy->next;
} 