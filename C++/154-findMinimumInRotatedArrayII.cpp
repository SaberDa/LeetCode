#include <iostream>
#include <vector>

using namespace std;

int main() {

    vector<int> nums;
    nums = { 2,2,2,0,1 };

    int left = 0;
    int right = nums.size() - 1;

    int ans = nums[left];
    while (left <= right) {
        int mid = (left + right) / 2;
        if (left < mid && mid < right && nums[left] == nums[mid] && nums[mid] == nums[right]) {
            left++;
            right--;
        } else if (nums[left] <= nums[mid]) {
            ans = (ans < nums[left]) ? ans : nums[left];
            left = mid + 1;
        } else {
            ans = (ans < nums[right]) ? ans : nums[right];
            right = mid - 1;
        }
    }

    cout << ans << endl;

    return 0;
}