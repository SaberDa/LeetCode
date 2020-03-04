#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void combinationUnit(vector<vector<int>>& res, vector<int>& temp, vector<int>& candidates, int target, int size) {
    if (target == 0) {
        if (find(res.begin(), res.end(), temp) == res.end()) {
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
    combinationUnit(res, temp, candidates, target - candidates[size-1], size-1);
    temp.pop_back();
    combinationUnit(res, temp, candidates, target, size - 1);
}

int main() {

    vector<int> candidates = { 10,1,2,7,6,1,5 };
    int target = 8;

    vector<vector<int>> res;
    vector<int> temp;
    
    sort(candidates.begin(), candidates.end());
    combinationUnit(res, temp, candidates, target, candidates.size());


    return 0;
}
