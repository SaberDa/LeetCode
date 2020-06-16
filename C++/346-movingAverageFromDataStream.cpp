#include <iostream>
#include <queue>

using namespace std;

class MovingAverage {
private:
    queue<int> q;
    int length = 0;
    int sum = 0;
public:
    MovingAverage(int size) {
        length = size;
    }

    double next(int val) {
        if (q.size() == length) {
            sum -= q.front();
            q.pop();
        }
        sum += val;
        q.push(val);
        return (double)sum/q.size();
    }
};