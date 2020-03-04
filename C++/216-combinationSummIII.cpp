#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void combinationUnit(vector<vector<int>>& res, vector<int>& temp, vector<int>& candidates, int target, int size, int k) {
    if (target == 0) {
        if (find(res.begin(), res.end(), temp) == res.end() && temp.size() == k) {
            res.push_back(temp);
        }
        return;
    }
    if (size <= 0 && target > 0) {
        return;
    }
    if (target < 0) {
        return;
    }
    temp.push_back(candidates[size-1]);
    combinationUnit(res, temp, candidates, target - candidates[size-1], size-1, k);
    temp.pop_back();
    combinationUnit(res, temp, candidates, target, size - 1, k);
}

int main() {

    int k;
    int n;

    k = 3;
    n = 7;

    vector<int> candidates = { 1,2,3,4,5,6,7,8,9 };

    int target = n;

    vector<vector<int>> res;
    vector<int> temp;
    
    combinationUnit(res, temp, candidates, target, candidates.size(), k);


    return 0;
}
