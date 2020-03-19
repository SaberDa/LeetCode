#include <iostream>
#include <unordered_set>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        // solution 1
        // count length
        // int Alength(0), Blength(0);
        // ListNode *temp(headA);
        // while (temp) {
        //     temp = temp->next;
        //     Alength++;
        // }
        // temp = headB;
        // while (temp) {
        //     temp = temp->next;
        //     Blength++;
        // }
        // if (Alength > Blength) {
        //     while (Alength-- != Blength) {
        //         headA = headA->next;
        //     }
        // } else {
        //     while (Alength != Blength--) {
        //         headB = headB->next;
        //     }
        // }
        // while (headA != headB) {
        //     headA = headA->next;
        //     headB = headB->next;
        // }
        // return headA;

        // solution 2
        // use hash set
        // unordered_set<ListNode*> set;
        // while (headB) {
        //     set.insert(headB);
        //     headB = headB->next;
        // }
        // while (headA && !set.count(headA)) {
        //     headA = headA->next;
        // }
        // return headA;

        // solution 3
        // use two pointers
        // ListNode *a(headA), *b(headB);
        // while (a != b) {
        //     a = a ? a->next : headA;
        //     b = b ? b->next : headB;
        // }
        // return a;

        // solution 4
        // create a circle 
        // then use Floyd's Tortoise and Hare algorithm
        if (!headA || !headB) {
            return NULL;
        }
        ListNode *tail(headA);
        while (tail->next) {
            tail = tail->next;
        }
        tail->next = headA;
        ListNode *slow(headB), *fast(headB);
        bool intersect = false;
        while (fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
            if (slow == fast) {
                intersect = true;
                break;
            }
        }
        if (intersect) {
            slow = headB;
            while (slow != fast) {
                slow = slow->next;
                fast = fast->next;
            }
            tail->next = NULL;
            return slow;
        }
        tail->next = NULL;
        return NULL;
    }
};