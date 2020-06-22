#include <iostream>
#include <vector>

using namespace std;

int missingElement(vector<int>& nums, int k) {
    for (int i = 1; i < nums.size(); i++) {
        int diff = nums[i] - nums[i - 1] - 1;
        if (diff >= k) return nums[i - 1] + k;
        else k -= diff;
    }
    return nums.back() + k;
}
