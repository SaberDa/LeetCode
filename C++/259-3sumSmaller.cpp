#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {

    vector<int> nums;
    nums.push_back(0);
    nums.push_back(-4);
    nums.push_back(-1);
    nums.push_back(1);
    nums.push_back(-1);
    nums.push_back(2);
    int target = -5;

    int flag = 0;
    int res = 0;

    if (nums.size() < 3) {
        return 0;
    }

    sort(nums.begin(), nums.end());

    for (int i = 0; i <= nums.size()-3; i++) {
        int m = i + 1;
        int r = nums.size() - 1;
        while (m < r) {
            res = nums[i] + nums[m] + nums[r];
            if (res > target) {
                r--;
                continue;
            } else if (res == target) {
                while (m < r && nums[r] == nums[r-1]) {
                    r--;
                }
                if (m == r) r += 1;
                int value = r - m - 1;
                flag += value;
                
                // cout << flag << endl;
                // break;
            } else if (res < target) {
                int value = r - m;
                flag += value;

                // cout << flag << endl;
                // break;
            }
            m++;
            r = nums.size() - 1;
            
        }
    }

    cout << flag << endl;
    return 0;
}