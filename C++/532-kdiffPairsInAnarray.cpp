#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int findPairs(vector<int>& nums, int k) {
    sort(nums.begin(), nums.end());
    int slow = 0, fast = 1;
    int res = 0;
    while (slow < nums.size() && fast < nums.size()) {
        if (nums[fast] - nums[slow] == k) {
            slow++, fast++;
            res++;
            while (fast < nums.size() && nums[fast] == nums[fast - 1]) fast++;
        } else if (nums[fast] - nums[slow] > k) {
            slow++;
            if (slow - fast == 0) fast++;
        } else {
            fast++;
        }
    }
    return res;
}