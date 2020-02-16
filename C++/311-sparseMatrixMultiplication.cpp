#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

int main() {

    vector<vector<int>> A;
    A.push_back({ 1,0,0 });
    A.push_back({ -1,0,3 });
    vector<vector<int>> B;
    B.push_back({ 7,0,0 });
    B.push_back({ 0,0,0 });
    B.push_back({ 0,0,1 });

    // if (A.empty() || B.empty()) {
    //     return 0;
    // }

    int m1 = A.size();
    int n1 = A[0].size();
    int m2 = B.size();
    int n2 = B[0].size();

    // store the nonzero points in A
    vector<pair<int, int>> sA;
    for (int i = 0; i < m1; i++) {
        for (int j = 0; j < n1; j++) {
            if (A[i][j]) {
                sA.push_back(make_pair(i, j));
            }
        }
    }

    // store the nonzero points in B, organized in row by row
    unordered_map<int, vector<int>> mB;
    for (int i = 0; i < m2; i++) {
        for (int j = 0; j < n2; j++) {
            if (B[i][j]) {
                mB[i].push_back(j);
            }
        }
    }


    // multiplication for sparse matrix
    vector<vector<int>> res(m1, vector<int>(n2, 0));
    for (auto & a : sA) {
        int i = a.first;
        int j = a.second;
        if (!mB.count(j)) {
            continue;
        }
        for (auto & k : mB[j]) {
            res[i][k] += A[i][j] * B[j][k];
        }
    }



    // output
    for (int i = 0; i < res.size(); i++) {
        for (int j = 0; j < res[0].size(); j++) {
            cout << res[i][j] << " ";
        }
        cout << " " << endl;
    }

    return 0;
}