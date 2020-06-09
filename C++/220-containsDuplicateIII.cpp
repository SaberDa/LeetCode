#include <iostream>
#include <vector>
#include <cmath>
#include <unordered_map>

using namespace std;

long long getBucketID(long long i, long long w) {
    return i < 0 ? (i + 1) / w - 1 : i / w;
}

bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t) {
    int n = nums.size();
    if (n < 2 || k < 1 || t < 0) return false;

    unordered_map<long long, long long> buckets;
    long long width = (long long)t + 1;
    for (int i = 0; i < n; i++) {
        long long id = getBucketID(nums[i], width);
        if (buckets.find(id) != buckets.end()) return true;
        if ((buckets.find(id - 1) != buckets.end() && nums[i] - buckets[id - 1] < width) ||
            (buckets.find(id + 1) != buckets.end() && buckets[id + 1] - nums[i])) {
                return true;
            }
        buckets[id] = nums[i];
        if (i >= k) {
            buckets.erase(getBucketID(nums[i - k], width));
        }
    }
    return false;
}