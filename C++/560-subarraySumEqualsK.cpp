#include <iostream>
#include <vector>
#include <map>

using namespace std;

int count = 0;

int subarraySum(vector<int>& nums, int k) {
    if (nums.empty()) {
        return 0;
    }
    map<int, int> mp;
    mp[0] = 1;
    int sum = 0;
    for (int i = 0; i < nums.size(); i++) {
        sum += nums[i];
        if (mp[sum - k]) {
            count += mp[sum - k];
        }
        mp[sum]++;
    }
    return count;
}