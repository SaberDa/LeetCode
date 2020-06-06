#include <iostream>
#include <vector>

using namespace std;

int rob(vector<int>& nums) {
    int x = 0, y = 0;
    for (int i = 0; i < nums.size(); i++) {
        if (i & 1) {
            x = max(nums[i] + x, y);
        } else {
            y = max(nums[i] + y, x);
        }
    }
    return max(x, y);
}