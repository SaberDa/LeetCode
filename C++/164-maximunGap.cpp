#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>


using namespace std;

int main() {

    vector<int> nums;
    nums.push_back(3);
    nums.push_back(6);
    nums.push_back(9);
    nums.push_back(1);

    if (nums.size() < 2) {
        return 0;
    }
    // sort(nums.begin(), nums.end());
    // int res = 0;
    // for (int i = 1; i < nums.size(); i++) {
    //     if (nums[i] - nums[i-1] > res) {
    //         res = nums[i] - nums[i-1];
    //     }
    // }

    // cout << res << endl;


    // bucket sort
    int n = nums.size();
    auto lu = minmax_element(nums.begin(), nums.end());
    // 获取数组中最大最小值
    int l = *lu.first;
    int u = *lu.second;
    // get buctet size
    int gap = max((u - l) / (n - 1), 1);
    // get bucket number
    int m = (u-l)/gap + 1;
    // init the max and min border vector
    vector<int> bucketMin(m ,INT_MAX);
    vector<int> bucketMax(m ,INT_MIN);
    // put elements into bucket
    for (auto i : nums) {
        // get bucket index
        int k = (i-l) / gap;
        if (i > bucketMax[k]) bucketMax[k] = i;
        if (i < bucketMin[k]) bucketMin[k] = i;
    }
    // caluate the max gap
    // use next bucket min value - current bucket max value
    int i = 0;
    int j;
    gap = bucketMax[0] - bucketMin[0];
    while (i < m) {
        j = i + 1;
        // delete empty bucket
        while (j < m && bucketMin[j] == INT_MAX && bucketMax[j] == INT_MIN) {
            j++;
        }
        if (j == m) {
            break;
        }
        gap = max(gap, bucketMin[j] - bucketMax[i]);
        i = j;
    }

    cout << gap << endl;

    return 0;
}
