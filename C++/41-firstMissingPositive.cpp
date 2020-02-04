#include <iostream>
#include <vector>

using namespace std;

// first point: 
// nums[i] should be (i+1)
// nums[nums[i] - 1] != nums[i]
// second point:
// the range of res should be [1, n+1]

int main() {

    vector<int> nums;
    nums.push_back(3);
    nums.push_back(4);
    nums.push_back(2);
    nums.push_back(1);

    
    if (nums.empty()) {
        return 1;
    }
    for (int i = 0; i < nums.size(); i++) {
        while (nums[i] > 0 
        && nums[i] <= nums.size() 
        && nums[nums[i] - 1] != nums[i]) {
            swap(nums[i], nums[nums[i] - 1]);
        }
    }
    int i = 1;
    for (auto x : nums) {
        if (x == i) {
            i++;
        }
    }
    cout << i << endl;

    return 0;
}