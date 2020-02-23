#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {

    vector<int> nums;
    nums.push_back(5);
    nums.push_back(7);
    nums.push_back(7);
    nums.push_back(8);
    nums.push_back(8);
    nums.push_back(10);
    int target = 8;

    vector<int> res(2, -1);
    if (nums.empty()) {
        return 0;
    }
    // solution 1
    // if (!binary_search(nums.begin(), nums.end(), target)) {
    //     cout << "not found" << endl;
    //     return 0;
    // }
    // int l = 0;
    // int r = nums.size()-1;
    // int m = (l+r) / 2;
    // while (nums[m] != target) {
    //     if (target < nums[m]) {
    //         r = m - 1;
    //     } else if (target > nums[m]) {
    //         l = m + 1;
    //     }
    //     m = (l+r) / 2;
    // }
    // int i = m;
    // while (i >= 0 && nums[i] == target) {
    //     i--;
    // }
    // res[0] = i + 1;
    // i = m+1;
    // while (i < nums.size() && nums[i] == target) {
    //     i++;
    // }
    // res[1] = i - 1;

    // solution 2
    // use lower_bound & upper_bound
    int left = lower_bound(nums.begin(), nums.end(), target) - nums.begin();
    int right = upper_bound(nums.begin(), nums.end(), target) - nums.begin();
    if (left == right) {
        return 0;
    } else {
        res[0] = left;
        res[1] = right-1;
    }
    // return (left == right) ? vector<int>{-1, -1} : vector<int>{left, right-1}; 

    for (auto x : res) {
        cout << x << endl;
    }

    return 0;
}