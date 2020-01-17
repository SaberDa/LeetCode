#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

int main() {

    vector<vector<int>> intervals;
    intervals.push_back({13, 15});
    intervals.push_back({1, 13});
    intervals.push_back({6, 9});

    if (intervals.empty()) {
        return 0;
    }

    vector<int> start;
    vector<int> end;
    for (int i = 0; i < intervals.size(); i++) {
        start.push_back(intervals[i][0]);
        end.push_back(intervals[i][1]);
    }

    sort(start.begin(), start.end());
    sort(end.begin(), end.end());

    int count = 0;
    int room = 0;

    for (int i = 0; i < intervals.size(); i++) {
        if (start[i] < end[count]) {
            room++;
        } else {
            count++;
        }
    }

    cout << room << endl;

    return 0;
}

