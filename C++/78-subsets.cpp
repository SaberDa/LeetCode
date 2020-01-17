#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void backtrack(vector<int>& nums, int k, vector<int> subset, vector<vector<int>>& res);

int main() {
    vector<int> nums;
    nums.push_back(1);
    nums.push_back(2);
    nums.push_back(3);

    vector<vector<int>> res;

    backtrack(nums, 0, vector<int> (), res);

    sort(res.begin(), res.end());


    for (int i = 0; i < res.size(); i++) {
        for (int j = 0; j < res[i].size(); j++) {
            cout << res[i][j] << " ";
        }
        cout << " " << endl;
    }
    return 0;
}

void backtrack(vector<int>& nums, int k, vector<int> subset, vector<vector<int>>& res) {
    if (k == nums.size()) {
        res.push_back(subset);
        return;
    }
    backtrack(nums, k+1, subset, res);
    subset.push_back(nums[k]);
    backtrack(nums, k+1, subset, res);
}