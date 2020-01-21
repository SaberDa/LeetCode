#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>

using namespace std;

int solution1() {
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

int main() {
    vector<int> nums;
    nums.push_back(0);
    nums.push_back(1);
    nums.push_back(2);
    nums.push_back(1);
    
    int ans = 0;
    unordered_map<int, int> m;
    for (auto x : nums) {
        if (m[x]) continue;
        int left = m[x-1];
        int right = m[x+1];
        m[x+right] = m[x-left] = m[x] = right + left + 1;
        ans = max(ans, m[x]);
    }
    cout << ans << endl;
    return 0;
}