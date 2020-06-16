#include <iostream>
#include <stack>

using namespace std;

class MaxStack {
private:
    stack<int> s1, s2;

    void addMax(int x) {
        if (s2.empty() || x >= s2.top()) s2.push(x);
    } 

public:
    MaxStack () {}

    void push(int x) {
        addMax(x);
        s1.push(x);
    }

    int pop() {
        if (s1.top() == s2.top()) s2.pop();
        int temp = s1.top();
        s1.pop();
        return temp;
    }

    int top() {
        return s1.top();
    }

    int peekMax() {
        return s2.top();
    }

    int popMax() {
        int temp = s2.top();
        stack<int> tem;
        while (s1.top() != s2.top()) {
            tem.push(s1.top());
            s1.pop();
        }
        s1.pop();
        s2.pop();
        while (!tem.empty()) {
            s1.push(tem.top());
            addMax(tem.top());
            tem.pop();
        }
        return temp;
    }
};