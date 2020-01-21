#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    vector<int> nums;
    nums.push_back(0);
    nums.push_back(1);
    nums.push_back(2);
    nums.push_back(1);
    // nums.push_back(3);
    // nums.push_back(2);

    int ans = 1;
    int temp = 1;
    if (nums.empty()) {
        return 0;
    }


    sort(nums.begin(), nums.end());

    for (int i = 1; i < nums.size(); i++) {
        if (nums[i] != nums[i-1]) {
            if (nums[i] == nums[i-1]+1) {
                temp++;   
            }
            else {
                temp = 1;
            }
            ans = max(ans, temp);
        }
    }

    cout << ans << endl;
    return 0;
}