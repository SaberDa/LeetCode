#include <iostream>
#include <vector>
#include <numeric>

using namespace std;

bool helper(vector<int>& nums, vector<int>& visited, int k, int pos, int sum, int size, int target) {
    if (k == 1) return true;
    if (sum == target && size > 0) return helper(nums, visited, k - 1, 0, 0, 0, target);
    for (int i = pos; i < nums.size(); i++) {
        if (!visited[i]) {
            visited[i] = 1;
            if (helper(nums, visited, k, i + 1, sum + nums[i], size++, target)) return true;
            visited[i] = 0;
        }
    }
    return false;
}

bool canPartitionKSubsets(vector<int>& nums, int k) {
    int sum = accumulate(nums.begin(), nums.end(), 0);
    if (sum <= 0 || sum % k) return false;
    vector<int> visited(nums.size(), 0);
    return helper(nums, visited, k, 0, 0, 0, sum / k);
}