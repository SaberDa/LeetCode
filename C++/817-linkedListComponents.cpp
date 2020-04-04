#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    int numComponents(ListNode* head, vector<int>& G) {
        // set of the subset elements which are considered unvisited initially
        unordered_set<int> unvisited(begin(G), end(G));
        int part = 0;
        if (!head) {
            return part;
        }
        ListNode* temp = head;
        // as we traverse through the list, we find all the nodes connected in G
        // from the current node and remove them from unvisited set
        while (temp) {
            // check if current node is in G or not
            if (unvisited.find(temp->val) != unvisited.end()) {
                part++;
                // now find all the nodes connects via current node
                // and remove them from unvisited set
                while (temp && unvisited.find(temp->val) != unvisited.end()) {
                    // remove the current from list of unvisited set
                    unvisited.erase(temp->val);
                    temp = temp->next;
                }
            }
            if (temp) {
                temp = temp->next;
            }
        }
        return part;
    }
};