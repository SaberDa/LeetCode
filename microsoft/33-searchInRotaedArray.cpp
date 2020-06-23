#include <vector>
#include <iostream>

using namespace std;

int search(vector<int>& nums, int target) {
    if (nums.empty()) return -1;
    int l = 0, r = nums.size() - 1;
    while (l <= r) {
        int m = l + (r - l) / 2;
        if (target == nums[m]) return m;
        if (nums[m] > nums[r]) {
            if (target >= nums[l] && target < nums[m]) r = m - 1;
            else l = m + 1;
        } else if (nums[m] < nums[l]) {
            if (target <= nums[r] && target > nums[m]) l = m + 1;
            else r = m - 1;
        } else r--;
    }
    return (nums[l] == target) ? l : -1;
}