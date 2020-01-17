#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {

    vector<int> nums;
    nums.push_back(1);
    nums.push_back(0);
    nums.push_back(-1);
    nums.push_back(-1);
    nums.push_back(-4);
    nums.push_back(2);
    int target = -1;

    vector<vector<int>> res;
    if (nums.size() < 4) {
        return 0;
    }
    if ((nums.size() == 4) && (nums[0]+nums[1]+nums[2]+nums[3] == target)) {
        res.push_back({nums[0], nums[1], nums[2], nums[3]});
        return 0;
    }
    sort(nums.begin(), nums.end());

    for (int l = 0; l <= nums.size()-4; l++) {
        while(l > 0 && l <= nums.size()-4 && nums[l] == nums[l-1]){l++;}
        for (int i = l+1; i <= nums.size()-3; i++) {
            while(i > l+1 && i <= nums.size()-3 && nums[i] == nums[i-1]){i++;}
            int m = i+1;
            int r = nums.size() - 1;
            while(m < r) {
                int sum = nums[l] + nums[i] + nums[m] + nums[r];
                if (sum == target) {
                    res.push_back({nums[l], nums[i], nums[m], nums[r]});
                    while (m<r && nums[r] == nums[r-1]) {
                        r--;
                    }
                    while (m<r && nums[m] == nums[m+1]) {
                        m++;
                    }
                    m++;
                    r--;
                    // break;
                } else if (sum > target) {
                    r--;
                } else {
                    m++;
                }
            }
        }  
    }
    

    for (int i = 0; i < res.size(); i++) {
        for (int j = 0; j < res[i].size(); j++) {
            cout << res[i][j] << " ";
        }
        cout << " " << endl;
    }


    return 0;
}