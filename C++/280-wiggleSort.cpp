#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {

    vector<int> nums;
    nums.push_back(1);
    nums.push_back(3);
    nums.push_back(2);
    nums.push_back(2);
    nums.push_back(3);
    nums.push_back(1);

    if (nums.empty()) {
        return 0;
    }

    for (int i = 1; i < nums.size(); i++) {
        if (i % 2 == 0) {
            if (nums[i-1] < nums[i]) {
                swap(nums[i-1], nums[i]);
            }
        }
        if (i % 2 == 1) {
            if (nums[i-1] > nums[i]) {
                swap(nums[i-1], nums[i]);
            }
        }
    }

    for (int i = 0; i< nums.size(); i++) {
        cout << nums[i] << endl;
    }

    return 0;
}