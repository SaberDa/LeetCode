#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {

    vector<int> nums = { 0,0,1,1,1,2,2,3,3,4 };

    if (nums.empty()) {
        return 0;
    }

    // solution 1
    // for (auto i = nums.begin(); i < nums.end() - 1;) {
    //     if (*i == *(i+1)) {
    //         nums.erase(i+1);
    //     } else {
    //         i++;
    //     }
    // }

    // solution 2
    // return i
    // int i(0), j(0);
    // while (j < nums.size()) {
    //     while (j < nums.size() - 1 && nums[j] == nums[j+1]) {
    //         j++;
    //     }
    //     nums[i] = nums[j];
    //     i++;
    //     j++;
    // }

    // solution 3
    // use unique()
    auto iter = unique(nums.begin(), nums.end());
    nums.erase(iter, nums.end());
    
    for (auto i : nums) {
        cout << i << endl;
    }
    cout << nums.size() << endl;

    return 0;
}