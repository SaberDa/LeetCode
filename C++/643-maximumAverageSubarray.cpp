#include <iostream>
#include <vector>

using namespace std;

double findMaxAverage(vector<int>& nums, int k) {
    if (nums.size() < k) return 0;
    int sum = 0, res = 0;
    for (int i = 0; i < nums.size(); i++) {
        sum += nums[i];
        if (i == k - 1) res = sum;
        if (i >= k) {
            sum -= nums[i - k];
            res = max(res, sum);
        }
    }
    return (double)res / k;
}