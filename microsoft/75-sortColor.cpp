#include <iostream>
#include <vector>

using namespace std;

void sortColors(vector<int>& nums) {
    for (int i = 0, j = 0, k = nums.size() - 1; j <= k;) {
        if (nums[j] == 0) {
            swap(nums[i], nums[j]);
            i++, j++;
        } else if (nums[j] == 2) {
            swap(nums[j], nums[k]);
            k--;
        } else j++;
    }
}