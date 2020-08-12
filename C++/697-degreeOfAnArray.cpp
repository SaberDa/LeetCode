#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

int findShortestSubArray(vector<int>& nums) {
    unordered_map<int, int> cnt, idx;
    int degree = 0, minLen = 0;
    for (int i = 0; i < nums.size(); i++) {
        if (!idx.count(nums[i])) idx[nums[i]] = i;
        cnt[nums[i]]++;
        if (cnt[nums[i]] == degree) minLen = min(minLen, i - idx[nums[i]] + 1);
        if (cnt[nums[i]] > degree) {
            degree = cnt[nums[i]];
            minLen = i - idx[nums[i]] + 1;
        }
    }
    return minLen;
}