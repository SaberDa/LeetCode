#include <iostream>
#include <vector>

using namespace std;

int triangleNumber(vector<int>& nums) {
    // bf, TLE
    // sort(nums.begin(), nums.end());
    // int res = 0;
    // for (int i = 0; i < nums.size(); i++) {
    //     for (int j = i + 1; j < nums.size(); j++) {
    //         for (int k = j + 1; k < nums.size(); k++) {
    //             if (nums[i] + nums[j] > nums[k]) res++;
    //         }
    //     }
    // }
    // return res;

    sort(nums.begin(), nums.end());
    int res = 0; 
    int n = nums.size();
    for (int k = n - 1; k > 1; k--) {
        int i = 0, j = k - 1;
        while (i < j) {
            if (nums[i] + nums[j] > nums[k]) {
                j--;
                res += j - i + 1;
            } else {
                i++;
            }
        }
    }
    return res;
}