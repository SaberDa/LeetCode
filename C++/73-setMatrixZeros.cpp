#include <iostream>
#include <vector>

using namespace std;

int main() {

    vector<vector<int>> matrix;
    matrix.push_back({ 1,1,1 });
    matrix.push_back({ 1,0,1 });
    matrix.push_back({ 1,1,1 });

    // vector<pair<int, int>> index;
    // for (int i = 0; i < matrix.size(); i++) {
    //     for (int j = 0; j < matrix[0].size(); j++) {
    //         if (matrix[i][j] == 0) {
    //             index.push_back({i, j});
    //         }
    //     }
    // }

    // for (auto x : index) {
    //     for (int i = 0; i < matrix.size(); i++) {
    //         matrix[i][x.second] = 0;
    //     }
    //     for (int i = 0; i < matrix[0].size(); i++) {
    //         matrix[x.first][i] = 0;
    //     }
    // }

    if (matrix.empty()) {
        return 0;
    }
    bool firstCol = false;
    bool firstRow = false;
    int n = matrix.size();
    int m = matrix[0].size();

    for (int i = 0; i < m; i++) {
        if (matrix[0][i] == 0) {
            firstCol = true;
            break;
        }
    }
    for (int i = 0; i < n; i++) {
        if (matrix[i][0] == 0) {
            firstRow = true;
            break;
        }
    }

    for (int i = 1; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (matrix[i][j] == 0) {
                matrix[0][j] = matrix[i][0] = 0;
            }
        }
    }
    for (int i = 1; i < m; i++) {
        if (matrix[0][i] == 0) {
            for (int j = 1; j < n; j++) {
                matrix[j][i] = 0;
            }
        }
    }
    for (int i = 1; i < n; i++) {
        if (matrix[i][0] == 0) {
            for (int j = 1; j < m; j++) {
                matrix[i][j] = 0;
            }
        }
    }
    if (firstCol) {
        for (int i = 0; i < m; i++) {
            matrix[0][i] = 0;
        }
    }
    if (firstRow) {
        for (int i = 0; i < n; i++) {
            matrix[i][0] = 0;
        }
    }

    for (int i = 0; i < matrix.size(); i++) {
        for (int j = 0; j < matrix[0].size(); j++) {
            cout << matrix[i][j] << " ";
        }
        cout << " " << endl;
    }



    return 0;
}