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


    // binary search
    // because the new vector is the rotated one
    // so we can use the mid one to judge where the rotate starts
    // if the mid is larger than the right bound
    // which means the origin first element is on the right side
    //  in this case, if the target is less than the mid and larger the left
    //  the target element may exist in the left side
    // else if the mid is less than the right bound
    // which means the origin first element is on the left side
    //  in this case, if the target is larger than the mid and less than the right
    //  the target element may exist in the right side


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