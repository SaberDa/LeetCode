#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool isMajorityElement(vector<int>& nums, int target) {
    return target == nums[(nums.size()-1) >> 1];
}

int main() {

    vector<int> nums = { 10,100,101,101 };
    int target = 101;

    bool res = isMajorityElement(nums, target);
    cout << res << endl;

    return 0;
}

