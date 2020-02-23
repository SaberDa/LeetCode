#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

int main() {

    vector<int> nums;
    nums.push_back(1);
    nums.push_back(2);
    nums.push_back(3);
    nums.push_back(1);

    if (nums.empty()) {
        return 0;
    }

    

    bool res = false;

    // sort(nums.begin(), nums.end());
    // for (int i = 1; i < nums.size(); i++) {
    //     if (nums[i-1] == nums[i]) {
    //         res = true;
    //     }
    // }

    unordered_map<int, int> m;
    for (auto i : nums) {
        m[i]++;
        if (m[i] > 1) {
            res = true;
            break;
        }
    }

    cout << res << endl;

    return 0;
}