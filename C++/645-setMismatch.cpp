#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

vector<int> findErrorsNums(vector<int>& nums) {
    vector<int> res;
    unordered_map<int, int> mp;
    int n = nums.size();
    int sum = (1 + n) * n / 2;
    int temp = 0;
    for (auto x : nums) {
        if (mp[x] == 1) res.push_back(x);
        mp[x]++;
        temp += x;
    }
    res.push_back(sum - (temp - res[0]));
    return res;
}