#include <iostream>
#include <vector>

using namespace std;

int numSubarrayProductLessThanK(vector<int>& nums, int k) {
    int sum = 1, res = 0;
    for (int i = 0, j = 0; j < nums.size(); ) {
        sum *= nums[j++];
        while (sum >= k && i < j) {
            sum /= nums[i++];
        }
        res += j - i;
    }
    return res;
}