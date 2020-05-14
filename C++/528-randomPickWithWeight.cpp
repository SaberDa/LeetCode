#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

class Solution {
private:
    vector<int> sum;
public:
    Solution(vector<int>& w) {
        for (int i = 1; i < w.size(); i++) {
            w[i] += w[i-1];
        }
        sum = w;
    }
    int pickIndex() {
        return upper_bound(sum.begin(), sum.end(), rand() % sum.back()) - sum.begin();
    }
};