#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    
    static bool compare(vector<int>& a, vector<int>& b) {
        if (a[0] == b[0]) {
            return a[1] < b[1];
        }
        return a[0] < b[0];
    }
    
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>> res;
        if (intervals.empty()) {
            return res;
        }
        sort(intervals.begin(), intervals.end(), compare);

        int count = 0;
        res.push_back(intervals[count]);

        for (int i = 1; i < intervals.size(); i++) {
            if (res[count][1] >= intervals[i][0]) {
                res[count][1] = max(res[count][1], intervals[i][1]);
            } else {
                res.push_back(intervals[i]);
                count++;
            }
        }
        return res;
    }
};


static bool compare(vector<int>& a, vector<int>& b) {
    if (a[0] == b[0]) {
        return a[1] < b[1];
    }
    return a[0] < b[0];
}

int main() {

    vector<vector<int>> intervals;
    intervals.push_back({1, 3});
    intervals.push_back({2, 6});
    intervals.push_back({8, 10});
    intervals.push_back({15, 18});


    // sliding window
    // first sort the two-dimensional vector
    // if current window's second bound is larger than the next vector's first bound
    // combine next vector into current window
    // use the max bound of current window's second bound and next vector's second bound
    

    vector<vector<int>> res;
    if (intervals.empty()) {
        return 0;
    }

    sort(intervals.begin(), intervals.end(), compare);

    int count = 0;
    res.push_back(intervals[count]);

    for (int i = 1; i < intervals.size(); i++) {
        if (res[count][1] >= intervals[i][0]) {
            res[count][1] = max(res[count][1], intervals[i][1]);
        } else {
            res.push_back(intervals[i]);
            count++;
        }
    }

    for (int i = 0; i < res.size(); i++) {
        for (int j = 0; j < res[i].size(); j++) {
            cout << res[i][j] << " ";
        }
        cout << " " << endl;
    }

}