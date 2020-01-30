#include <iostream>
#include <vector>

using namespace std;

int main() {

    vector<int> nums;
    nums.push_back(5);
    nums.push_back(1);
    nums.push_back(5);
    nums.push_back(5);
    nums.push_back(2);
    nums.push_back(5);
    nums.push_back(4);

    if (nums.empty()) {
        return 0;
    }

    bool res = false;

    // int i = 0;
    // while (i < nums.size() - 2 && nums[i] >= nums[i+1]) {
    //     i++;
    // }
    // int min = nums[i];
    // int secMin = nums[i+1];
    // for (int j = i + 2; j < nums.size(); j++) {
    //     if (nums[j] > secMin) {
    //         res = true;
    //     }
    //     if (nums[j] > min && nums[j] < secMin) {
    //         secMin = nums[j];
    //     }
    //     if (nums[j] < min) {
    //         while (j < nums.size() - 2 && nums[j] >= nums[j+1]) {
    //             j++;
    //         }
    //         i = j;
    //         min = nums[i];
    //         secMin = nums[i+1];
    //     }
    // }

    int c1 = INT_MAX;
    int c2 = INT_MAX;
    for (auto x : nums) {
        if (x <= c1) c1 = x;
        else if (x <= c2) c2 = x;
        else res = true; 
    }


    cout << res << endl;

    return 0;
}