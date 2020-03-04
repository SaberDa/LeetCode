#include <iostream>
#include <vector>

using namespace std;



void combinationUnit(vector<vector<int>>& res, vector<int>& temp, vector<int>& candidates, int target, int size) {
    if (target == 0) {
        res.push_back(temp);
        return;
    }
    if (target < 0) {
        return;
    }
    if (target > 0 && size <= 0) {
        return;
    }
    temp.push_back(candidates[size-1]);
    combinationUnit(res, temp, candidates, target-candidates[size-1], size);
    temp.pop_back();
    combinationUnit(res, temp, candidates, target, size - 1);
}


int main() {

    vector<int> candidates = { 2,3,6,7 };
    int target = 7;

    vector<vector<int>> res;
    vector<int> temp;

    combinationUnit(res, temp, candidates, target, candidates.size());



    return 0;
}