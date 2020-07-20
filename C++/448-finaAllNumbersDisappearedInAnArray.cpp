#include <iostream>
#include <vector>

using namespace std;

vector<int> findDisappearedNumbers(vector<int>& nums) {
    vector<int> res;
    for (auto x : nums) {
        if (nums[abs(x) - 1] > 0) nums[abs(x) - 1] *= -1;
    }
    for (int i = 1; i < nums.size(); i++) {
        if (nums[i] > 0) res.push_back(i + 1);
    }
    return res;
}