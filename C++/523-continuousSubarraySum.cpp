#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

// time limit exceeded
// bool checkSubarraySum(vector<int>& nums, int k) {
//     int n = nums.size();
//     for (int i = 0; i < n - 1; i++) {
//         int sum = nums[i];
//         for (int j = i+1; j < n; j++) {
//             sum += nums[j];
//             if (k == 0) {
//                 if (sum == k) {
//                     return true;
//                 }
//             } else {
//                 if (sum % k == 0) {
//                     return true;
//                 }
//             }
//         }
//     }
//     return false;
// }

bool checkSubarraySum(vector<int>& nums, int k) {
    unordered_map<int, int> mp;
    mp[0] = -1;
    for (int i = 0, sum = 0; i < nums.size(); i++) {
        sum = k ? (sum + nums[i]) % k : sum + nums[i];
        if (!mp.count(sum)) {
            mp[sum] = i;
        } else if (i - mp[sum] > 1) {
            return true;
        }
    }
    return false;
}

int main() {
    vector<int> nums({23, 2, 4, 6, 7});
    int k = 6;
    cout << checkSubarraySum(nums, k) << endl;
    return 0;
}