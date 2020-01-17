#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <functional>

using namespace std;

void addNum(int num, priority_queue<int>& left, priority_queue<int, vector<int>, greater<int> >& right) {

    if (left.empty() || num <= left.top()) {
        left.push(num);
    } else {
        right.push(num);
    }


    if (left.size() > right.size()+1) {
        int temp = left.top();
        left.pop();
        right.push(temp);
    }

    if (right.size() > left.size()) {
        int temp = right.top();
        right.pop();
        left.push(temp);
    }
    

}

double findMedian() {
    priority_queue<int> left;
    priority_queue<int, vector<int>, greater<int> > right;

    addNum(1, left, right);
    addNum(2, left, right);
    addNum(2, left, right);

    double res;

    if (left.size() == right.size()) {
        res = (left.top() + right.top()) / 2.0;
    } else {
        res = left.top();
    }
    cout << res << endl;

    return res;
}

int main() {
    findMedian();
    return 0;
}
