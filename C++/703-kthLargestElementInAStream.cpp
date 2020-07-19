#include <iostream>
#include <vector>
#include <queue>

using namespace std;

class KthLargest {
private:

    struct comp {
        bool operator() (int& a, int& b) const {
            return a > b;
        }
    };

    int size = 0;
    priority_queue<int, vector<int>, comp> pq;

public:
    KthLargest(int k, vector<int>& nums) {
        size = k;
        for (auto x : nums) add(x);
    }
    
    int add(int val) {
        pq.push(val);
        if (pq.size() > size) pq.pop();
        return pq.top();
    }
};