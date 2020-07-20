#include <iostream>
#include <vector>

using namespace std;

vector<int> findDuplicates(vector<int>& nums) {
    vector<int> res;
    for (auto x : nums) {
        if (nums[abs(x) - 1] < 0) res.push_back(abs(x));
        nums[abs(x) - 1] *= -1;
    }
    return res;
}