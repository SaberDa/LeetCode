#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {

    vector<int> nums = { 1,5,8,4,7,6,5,3,1 };

    if (nums.empty()) {
        return 0;
    }
    for (int i = nums.size() - 1; i >= 1; i--) {
        if (nums[i-1] < nums[i]) {
            for (int j = nums.size() -1; j >= i; j--) {
                if (nums[j] > nums[i-1]) {
                    swap(nums[i-1],nums[j]);
                    sort(nums.begin() + i, nums.end());
                    return 0;
                }
            }
        }
    }
    reverse(nums.begin(), nums.end());

    return 0;
}