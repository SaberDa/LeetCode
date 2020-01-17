#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

static bool compare(vector<int>& a, vector<int>& b) {
    if (a[0] == b[0]) {
        return a[1] < b[1];
    }
    return a[0] < b[0];
}

int main() {

    vector<vector<int>> intervals;
    intervals.push_back({7, 10});
    intervals.push_back({2, 4});
    intervals.push_back({15, 20});

    bool res = true;

    if (intervals.empty()) {
        res = true;
        return 0;
    }

    sort(intervals.begin(), intervals.end(), compare);

    for (int i = 0; i < intervals.size()-1; i++) {
        if (intervals[i][1] > intervals[i+1][0]) {
            res = false;
        }
    }

    cout << res << endl;
    return 0;

}