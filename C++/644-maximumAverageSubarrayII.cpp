#include <iostream>
#include <vector>

using namespace std;

bool canReach(vector<int>& nums, double &mid, int &k) {
    vector<double> temp(nums.size() + 1);
    for (int i = 1; i < temp.size(); i++) {
        temp[i] = temp[i - 1] + (double)nums[i - 1] - mid;
    }
    double preMin = 0.0;
    for (int i = k; i < temp.size(); i++) {
        if (temp[i] > preMin) return true;
        preMin = min(preMin, temp[i - k + 1]);
    }
    return false;
}

double findMaxAverage(vector<int>& nums, int k) {
    int minV = INT_MAX, maxV = INT_MIN;
    int n = nums.size();
    for (auto c : nums) {
        minV = min(minV, c);
        maxV = max(maxV, c);
    }
    double l = (double)minV, r = (double)maxV;
    while (r - l > 10e-6) {
        double mid = l + (r - l) / 2;
        if (canReach(nums, mid, k)) l = mid;
        else r = mid;
    }
    return (l + r) / 2;
}