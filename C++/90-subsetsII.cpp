#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void backtrack(vector<int>& nums, int k, vector<int> subset, vector<vector<int>>& res);

int main() {
    vector<int> nums;
    nums.push_back(4);
    nums.push_back(4);
    nums.push_back(4);
    nums.push_back(1);
    nums.push_back(4);

    vector<vector<int>> res;

    backtrack(nums, 0, vector<int> (), res);

    // use backtrack to generate all the subsets
    // sort the results
    // then find the repeated ones
    // delete them

    for (int i = 0; i < res.size(); i++) {
        sort(res[i].begin(), res[i].end());
    }

    sort(res.begin(), res.end());

    vector<vector<int>>::iterator iter;

    iter = unique(res.begin(), res.end());

    res.erase(iter, res.end());

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