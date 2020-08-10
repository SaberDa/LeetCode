#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int findUnsortedSubarray(vector<int>& nums) {
    // sort
    vector<int> temp = nums;
    sort(temp.begin(), temp.end());
    int l = 0, r = nums.size() - 1;
    for (; l < nums.size(); l++) {
        if (temp[l] != nums[l]) break;
    }
    for (; r >= 0; r--) {
        if (temp[r] != nums[r]) break;
    }
    if (l >= r) return 0;
    return r - l + 1;

    // two pass
    int m = nums[0];
    int size = nums.size();
    int l = size, r = -1;
    for (int i = 1; i < size; i++) {
        if (nums[i] < m) r = i;
        m = max(m, nums[i]);
    }
    m = nums[size - 1];
    for (int i = size - 1; i >= 0; i--) {
        if (nums[i] > m) l = i;
        m = min(m, nums[i]);
    } 
    return max(0, r - l + 1);
}