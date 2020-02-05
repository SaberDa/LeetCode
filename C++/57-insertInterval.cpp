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

// int main() {

//     vector<vector<int>> intervals;
//     intervals.push_back({1, 3});
//     intervals.push_back({6, 9});


//     vector<vector<int>> newInterval;
//     newInterval.push_back({2, 5});


//     int first = newInterval[0][0];
//     int last = newInterval[0][1];

//     vector<vector<int>> res;
//     if (newInterval.empty()) {
//         return 0;
//     }
//     if (intervals.empty()) {
//         res.push_back({first, last});
//         return 0;
//     }


//     intervals.push_back({first, last});

//     sort(intervals.begin(), intervals.end(), compare);

//     int count = 0;
//     res.push_back(intervals[count]);

//     for (int i = 1; i < intervals.size(); i++) {
//         if (res[count][1] >= intervals[i][0]) {
//             res[count][1] = max(res[count][1], intervals[i][1]);
//         } else {
//             res.push_back(intervals[i]);
//             count++;
//         }
//     }

//     for (int i = 0; i < res.size(); i++) {
//         for (int j = 0; j < res[i].size(); j++) {
//             cout << res[i][j] << " ";
//         }
//         cout << " " << endl;
//     }


//     return 0;
// }

int main() {

    vector<vector<int>> intervals;
    intervals.push_back({1, 3});
    intervals.push_back({6, 9});


    vector<vector<int>> newInterval;
    newInterval.push_back({2, 5});

    // first, find the index that insert vector should be inserted
    // we just compare the vector's second bound with the insert vector's first bound
    // if current vector's second bound is less than the insert vector's first bound
    // then push current vector into result and judge next vector
    // if current vector's second bound is larger than the insert vector's fitst bound
    // we combine current vector and insert vector as a new vector
    // this new vector's first bound is current vector's first bound
    // the second bound is the max of current vector's second bound and insert vector's second bound
    // then push the left vectors in the origin vector into result

    vector<vector<int>> res;
    if (newInterval.empty()) {
        // return intervals;
        return 0;
    }
    if (intervals.empty()) {
        res.push_back({newInterval[0][0], newInterval[0][1]});
        // return res;
        return 0;
    }

    int count = 0;
    int begin = newInterval[0][0];
    int end = newInterval[0][1];
    int length = intervals.size();

    while (count < length && intervals[count][1] < begin) {
        res.push_back(intervals[count]);
        count++;
    }

    while (count < length && intervals[count][0] <= end) {
        begin = min(begin, intervals[count][0]);
        end = max(end, intervals[count][1]);
        count++;
    }

    res.push_back({begin, end});

    while (count < length) {
        res.push_back(intervals[count]);
        count++;
    }
    

    for (int i = 0; i < res.size(); i++) {
        for (int j = 0; j < res[i].size(); j++) {
            cout << res[i][j] << " ";
        }
        cout << " " << endl;
    }


}