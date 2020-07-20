#include <iostream>
#include <vector>

using namespace std;

int helper(vector<int>& nums, int res) {
    int size = nums.size();
    return ((res + nums[res]) % size + size) % size;
}

bool circularArrayLoop(vector<int>& nums) {
    if (nums.empty()) return false;
    for (auto x : nums) if (x == 0) return false;
    for (int i = 0; i < nums.size(); i++) {
        int slow = i;
        int fast = helper(nums, slow);
        bool dir = (nums[slow] > 0);
        if (slow == fast) {
            nums[i] = 0;
            continue;
        }
        while (slow != fast && nums[fast] != 0) {
            if ((nums[fast] > 0 )!= dir) break;
            slow = helper(nums, slow);
            fast = helper(nums, fast);
            if ((nums[fast] > 0) != dir) break;
            fast = helper(nums, fast);
        }
        if (slow == fast && fast != helper(nums, fast)) return true;
        nums[i] = 0;
    }
    return false;
}