#include <iostream>
#include <vector>
#include <numeric>

using namespace std;

int pathSum(vector<int>& nums) {
    if (nums.empty()) return 0;
    vector<int> tree(8, 0);
    int dep = nums.back() / 100;
    int n = nums.size(), ans = 0;
    for (int i = 1, j = 0; i <= dep; i++) {
        vector<int> temp(8, 0);
        while (j < n && nums[j] / 100 == i) {
            int pos = nums[j] % 100 / 10 - 1;
            temp[pos] = nums[j] % 10 + tree[pos / 2];
            j++;
        }
        for (int k = 0; k < 4; k++) {
            if (temp[k * 2] == 0 && temp[k * 2 + 1] == 0) {
                ans += tree[k];
            }
        }
        swap(tree, temp);
    }
    return accumulate(tree.begin(), tree.end(), ans);
}