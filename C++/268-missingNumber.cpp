#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

int missingNumber(vector<int>& nums) {
    // int n = nums.size();
    // int tSum = (1 + n) * n / 2;
    // int fSum = 0;
    // for (auto x : nums) fSum += x;
    // return tSum - fSum;

    unordered_set<int> s;
    for (auto x : nums) s.insert(x);
    for (int i = 0; i < nums.size() + 1; i++) {
        if (!s.count(i)) return i;
    }
    return -1;
}