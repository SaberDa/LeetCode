#include <iostream>
#include <vector>

using namespace std;

int main() {

    vector<int> nums;
    // nums.push_back(1);
    nums.push_back(3);
    nums.push_back(6);
    nums.push_back(0);
    nums.push_back(0);
    // nums.push_back(1);
    // nums.push_back(2);
    int target;

    target = 1;

    if (nums.empty()) {
        return -1;
    }

    int l = 0;
    int r = nums.size()-1;
    int res = -1;
    while (l < r) {
        int m = (l+r)/2;
        if (target == nums[m]) {
            return m;
        }
        if (nums[r] < nums[m]) {
            if (target < nums[m] && target >= nums[l]) {
                r = m;
            } else {
                l = m + 1;
            }
        } else if (nums[r] > nums[m]) {
            if (target > nums[m] && target <= nums[r]) {
                l = m + 1;
            } else {
                r = m;
            }
        } else {
            r--;
        }
    }
    
    res = (target == nums[l]) ? l : -1;
    cout << res << endl;

    return 0;
}