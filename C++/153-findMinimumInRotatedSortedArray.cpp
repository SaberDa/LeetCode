#include <iostream>
#include <vector>

using namespace std;

int main() {

    vector<int> nums;
    nums = { 4,5,6,7,0,1,2 };

    int first = 0;
    int last = nums.size() - 1;

    while (first <= last) {
        if (last - first == 1 || last - first == 0) {
            if (nums[first] < nums[last]) {
                return nums[first];
            } else {
                return nums[last];
            }
        }

        int mid = (first + last) / 2;
        if (nums[first] > nums[mid]) {
            last = mid;
        } else if (nums[last] <= nums[mid]) {
            first = mid;
        } else {
            cout << nums[first] << endl;
            return nums[first];
        }
    }

    // return min_element(nums.begin(), nums.end());

    return 0;
}