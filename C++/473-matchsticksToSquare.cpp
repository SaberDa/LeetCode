#include <iostream>
#include <vector>
#include <numeric>
#include <algorithm>

using namespace std;

bool helper(vector<int>& nums, vector<int>& visited, int size, int length, int pos, int n, int count, bool newSide) {
    if (length > size) return false;
    if (length == size) {
        count++;
        length = 0;
        newSide = true;
    }
    if (count == 3) return true;
    length += nums[pos];
    visited[pos] = 1;
    for (int i = newSide ? 0 : pos + 1; i < n; i++) {
        if (!visited[i] && helper(nums, visited, size, length, i, n, count, false)) {
            return true;
        }
    }
    visited[pos] = 0;
    return false;
}

bool makesquare(vector<int>& nums) {
    if (nums.empty()) return false;
    int sum = 0, maxlen = 0, n = nums.size();
    sum = accumulate(nums.begin(), nums.end(), 0);
    maxlen = *max_element(nums.begin(), nums.end());
    int size = sum / 4;
    if (sum == 0 || sum % 4 || maxlen > size) return false;
    vector<int> visited(n, 0);
    return helper(nums, visited, size, 0, 0, n, 0, false);
}