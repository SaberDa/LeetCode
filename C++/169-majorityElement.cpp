#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

// solution 2
// use nth_element and bit calculate
// If the elements are sorted in increasing order, the majority element can be found at index nums.size() / 2
// Instead of sorting, we use the quickselect algorithm to find the element at index nums.size() / 2 after sorting.
// n & 1 ==> n % 2
// n >> 1 ==> n / 2
int majorityElement(vector<int>& nums) {
    nth_element(nums.begin(), nums.begin() + (nums.size() >> 1), nums.end());
    return nums[nums.size() >> 1];
}

int main() {

    vector<int> nums = { 2,2,1,1,1,2,2 };

    int res = 0;
    unordered_map<int, int> count;
    for (auto n : nums) {
        count[n]++;
    }
    int range = 0;
    for (auto iter = count.begin(); iter != count.end(); iter++) {
        if (iter->second > range) {
            range = iter->second;
            res = iter->first;
        }
    }

    cout << res << endl;

    return 0;
}