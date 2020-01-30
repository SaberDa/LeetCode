#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

// Floyd's Tortoise and Hare
// 环检测算法

int main() {

    vector<int> nums;
    nums.push_back(1);
    nums.push_back(3);
    nums.push_back(4);
    nums.push_back(2);
    nums.push_back(2);

    if (nums.empty()) {
        return 0;
    }

    // phase 1
    int slow = nums[0];
    int fast = nums[nums[0]];
    while (slow != fast) {
        slow = nums[slow];
        fast = nums[nums[fast]];
    }
    // phase 2
    slow = 0;
    while (slow != fast) {
        slow = nums[slow];
        fast = nums[fast];
    }
    
    cout << slow << endl;

    return 0;
}