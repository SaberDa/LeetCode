#include <iosteram>
#include <vector>
#include <queue>

using namespace std;

int smallestDistancePair(vector<int>& nums, int k) {
    // TLE
    // auto comp = [](int& a, int& b){return a > b;};
    // priority_queue<int, vector<int>, decltype(comp)> pq(comp);
    // for (int i = 0; i < nums.size(); i++) {
    //     for (int j = i + 1; j < nums.size(); j++) {
    //         pq.push(abs(nums[i] - nums[j]));
    //     }
    // }
    // k = k - 1;
    // while (k--) pq.pop();
    // return pq.top();

    // binary search
    sort(nums.begin(), nums.end());
    int l = INT_MAX;
    int r = nums.back() - nums[0];
    for (int i = 1; i < nums.size(); i++) {
        l = min(l, nums[i] - nums[i - 1]);
    }
    while (l < r) {
        int m = l + (r - l) / 2;
        int cnt = 0;
        for (int i = 0, j = 0; i < nums.size(); i++) {
            while (j < nums.size() && nums[j] - nums[i] <= m) j++;
            cnt += j - i - 1;
        }
        if (cnt < k) l = m + 1;
        else r = m;
    }
    return l;
}