#include <isotream>
#include <queue>

using namespace std;

class MyStack {
private:
    queue<int> q1, q2;
    int last;
    bool last_valid;
public:
    MyStack(): last(0), last_valid(false) { }

    void push(int x) {
        if (!last_valid) {
            last = x;
            last_valid = true;
        } else {
            auto& q = q1.size() ? q1 : q2;
            q.push(last);
            last = x;
        }
    }

    int pop() {
        get_last();
        last_valid = false;
        return last;
    }

    int top() {
        get_last();
        return last;
    }

    bool empty() {
        return q1.empty() && q2.empty() && !last_valid;
    }
protected:
    void get_last() {
        if (last_valid) return;
        auto& q_from = q1.size() ? q1 : q2;
        auto& q_to = q1.size() ? q2 : q1;
        while (q_from.size() > 1) {
            q_to.push(q_from.front());
            q_from.pop();
        }
        last = q_from.front();
        q_from.pop();
        last_valid = true;
    }
};