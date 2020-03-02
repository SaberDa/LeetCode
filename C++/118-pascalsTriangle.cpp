#include <iostream>
#include <vector>

using namespace std;

int main() {

    int numRows = 5;
    vector<vector<int>> res(numRows);
    if (numRows == 0) return 0;
    res[0].push_back(1);
    for (int i = 1; i < numRows; i++) {
        res[i].push_back(1);
        for (int j = 1; j < i; j++) {
            res[i].push_back(res[i-1][j-1] + res[i-1][j]);
        }
        res[i].push_back(1);
    }

    for (int i = 0; i < res.size(); i++) {
        for (int j = 0; j < res[i].size(); j++) {
            cout << res[i][j] << " ";
        }
        cout << " " << endl;
    }

    return 0;
}