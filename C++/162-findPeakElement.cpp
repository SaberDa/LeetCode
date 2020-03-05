#include <iostream>
#include <vector>

using namespace std;

int main() {

    vector<int> nums = { 1,2,1,3,5,6,4 };

    if (nums.size() <= 1) {
        return 0;
    }

    int left = 0;
    int right = nums.size() - 2;
    while (left <= right) {
        int mid = (left + right) / 2;
        if (nums[mid] <= nums[mid+1]) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }

    cout << left << endl;

    return 0;
}