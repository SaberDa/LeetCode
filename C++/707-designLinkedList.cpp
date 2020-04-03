#include <iostream>

using namespace std;

struct Node {
    int val;
    Node* next;
    Node(int x) : val(x), next(NULL) {}
};

class MyLinkedList {
public:
    Node* head;
    Node* tail;
    int size;
    MyLinkedList() {
        this->head = NULL;
        this->tail = NULL;
        this->size = 0;
    }

    int get(int index) {
        if (index >= this->size) {
            return -1;
        }
        Node* temp = this->head;
        int count = 0;
        while (temp) {
            if (count++ == index) {
                return temp->val;
            }
            temp = temp->next;
        }
        return -1;
    }

    void addAtHead(int val) {
        Node* temp = new Node(val);
        if (this->head == NULL) {
            this->head = temp;
            this->tail = temp;
        } else {
            temp->next = this->head;
            this->head = temp;
        }
        this->size++;
    }

    void addAtTail(int val) {
        Node *temp = new Node(val);
        if (this->tail == NULL) {
            this->head = temp;
            this->tail = temp;
        } else {
            this->tail->next = temp;
            this->tail = temp;
        }
        this->size++;
    }

    void addAtIndex(int index, int val) {
        if (index > this->size) {
            return;
        }
        if (index == this->size) {
            this->addAtTail(val);
            return;
        }
        if (index == 0) {
            this->addAtHead(val);
            return;
        }
        int count = 0;
        Node* temp = this->head;
        while (temp) {
            if (count++ == index - 1) {
                Node* mid = new Node(val);
                mid->next = temp->next;
                temp->next = mid;
                break;
            }
            temp = temp->next;
        }
        this->size++;
    }

    void deleteAtIndex(int index) {
        if (index >= this->size) {
            return;
        }
        if (index == 0) {
            this->head = this->head->next;
        } else if (index == this->size - 1) {
            int count = 0;
            Node* temp = this->head;
            for (int i = 0; i < index-1; i++) {
                temp = temp->next;
            }
            temp->next = temp->next->next;
            this->tail = temp;
        } else {
            int count = 0;
            Node* temp = this->head;
            for (int i = 0; i < index-1; i++) {
                temp = temp->next;
            }
            temp->next = temp->next->next;
        }
        this->size--;
    }
};