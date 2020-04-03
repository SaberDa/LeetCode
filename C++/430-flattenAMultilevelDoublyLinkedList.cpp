#include <iostream>

using namespace std;

class Node {
public:
    int val;
    Node* prev;
    Node* next;
    Node* child;
};

class Solution {
public:
    Node* flatten(Node* head) {
        if (head) {
            tail(head);
        }
        return head;
    }

    Node* tail(Node* head) {
        Node* node = head;
        Node* list_tail = NULL;
        do {
            if (node->child) {
                // recurse into sub-list, and assume it is flat on return
                Node* splice_tail = tail(node->child);

                // fixup the pointers to splice the new flat array into us
                Node* after_splice = node->next;
                node->next = node->child;
                node->child->prev = node;
                splice_tail->next = after_splice;

                // check that node wasn't the end of a list before splicing the next
                // nonexistant node in
                if (after_splice) {
                    after_splice->prev = splice_tail;
                }

                // enforce the flatness
                node->child = NULL;
                // hop over the spliced-in sub-list to avoid redundant work traversing through it
                node = splice_tail;
            }
            // we assign this n times in the loop so we have the last value of it ready on return
            list_tail = node;
            node = node->next;
        } while (node != NULL);
        return list_tail;
    }
};