#include <iostream>
#include <vector>
#include <algorithm>

// Boyer-Moore Majority Vote algorithm

using namespace std;

vector<int> main() {

    vector<int> nums = { 1,1,1,3,3,2,2,2 };




    if (nums.empty()) {
        return 0;
    }

    // int length1 = nums.size() / 3;
    // int length2 = nums.size() * 2 / 3;
    // nth_element(nums.begin(), nums.begin() + length1, nums.end());
    // nth_element(nums.begin(), nums.begin() + length2, nums.end());
    // if (nums[length1] != nums[length2]) {
    //     res.push_back(nums[length1]);
    //     res.push_back(nums[length2]);
    // } else {
    //     res.push_back(nums[length1]);
    // }

    int numFirst = 0;
    int numSecond = 0;
    int countFirst = 0;
    int countSecond = 0;
    for (auto i : nums) {
        if (countFirst == 0 && i != numSecond) {
            numFirst = i;
        }
        if (countSecond == 0 && i != numFirst) {
            numSecond = i;
        }
        if (i == numFirst) {
            countFirst++;
        }
        if (i == numSecond) {
            countSecond++;
        }
        if (i != numFirst && i != numSecond) {
            countFirst--;
            countSecond--;
        }
    }
    int count1 = 0;
    int count2 = 0;
    for (auto i : nums) {
        if (numFirst == i) {
            count1++;
        } else if (numSecond == i) {
            count2++;
        }
    }
    if (count1 > nums.size() / 3 && count2 > nums.size() / 3) {
        return {numFirst, numSecond};
    }
    if (count1 > nums.size() / 3) {
        return {numFirst};
    }
    if (count2 > nums.size() / 3) {
        return {numSecond};
    }
    return vector<int>();

}