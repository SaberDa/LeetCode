#include <vector>
#include <unordered_map>

using namespace std;

unordered_map<int, int> mp;

int combinationSum4(vector<int>& nums, int target) {
    if (target == 0) return 1;
    if (mp.count(target)) return mp[target];
    int sum = 0;
    for (auto x : nums) {
        if (target >= x) {
            sum += combinationSum4(nums, target - x);
        }
    }
    mp[target] = sum;
    return sum;
}