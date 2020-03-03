#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {

    vector<vector<int>> matrix;
    matrix.push_back({ 1,3,5,7 });
    matrix.push_back({ 10,11,16,20 });
    matrix.push_back({ 23,30,34,50 });

    int target = 34;
    bool res = false;

    if (matrix.empty()) {
        return 0;
    }

    int m = matrix.size();
    int n = matrix[0].size();
    int l = 0;
    int r = m * n - 1;

    while (l <= r) {
        int mid = (l + r) / 2;
        int val = matrix[mid/n][mid%n];
        if (val > target) {
            r = mid - 1;
        } else if (val < target) {
            l = mid + 1;
        } else {
            res = true;
            break;
        }
    }

    cout << res << endl;

    return 0;
}