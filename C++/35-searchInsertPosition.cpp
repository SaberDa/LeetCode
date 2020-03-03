#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {

    vector<int> nums;
    nums = { 1,3,5,6 };
    int target;

    target = 5;
    
    if (nums.empty()) {
        return 0;
    }


    // if (find(nums.begin(), nums.end(), target) != nums.end()) {
    //     return find(nums.begin(), nums.end(), target)-nums.begin();
    // } else {
    //     nums.push_back(target);
    //     sort(nums.begin(), nums.end());
    //     return find(nums.begin(), nums.end(), target)-nums.begin();
    // }

    if (target < *nums.begin()) {
        return 0;
    } else if (target > nums.back()) {
        return nums.size();
    } else {
        for (int i = 0; i < nums.size(); i++) {
            if (target == nums.at(i)) {
                return i;
            } else if (target > nums.at(i) && target < nums.at(i+1)) {
                return i+1;
            }
        }
    }

    return 0;
}
