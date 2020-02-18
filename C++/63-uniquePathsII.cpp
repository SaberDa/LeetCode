#include <iostream>
#include <vector>

using namespace std;

int main() {

    vector<vector<int>> obstacleGrid;
    obstacleGrid.push_back({ 0,0,1,0 });
    obstacleGrid.push_back({ 0,0,0,0 });
    obstacleGrid.push_back({ 1,1,1,0 });
    obstacleGrid.push_back({ 0,0,0,0 });
    // obstacleGrid.push_back({1});

    if (obstacleGrid.empty()) {
        return 0;
    }


    // for (int i = 0; i < obstacleGrid.size(); i++) {
    //     for (int j = 0; j < obstacleGrid[0].size(); j++) {
    //         if (obstacleGrid[i][j] == 1) {
    //             obstacleGrid[i][j] = -1;
    //         }
    //     }
    // }


    // int flag = 1;
    // for (int i = 0; i < obstacleGrid.size(); i++) {
    //     if (obstacleGrid[i][0] != -1 && flag) {
    //         obstacleGrid[i][0] = 1;
    //     } else {
    //         obstacleGrid[i][0] = 0;
    //         flag = 0;
    //     }
    // }
    // flag = 1;
    // for (int i = 1; i < obstacleGrid[0].size(); i++) {
    //     if (obstacleGrid[0][i] != -1 && flag) {
    //         obstacleGrid[0][i] = 1;
    //     } else {
    //         obstacleGrid[0][i] = 0;
    //         flag = 0;
    //     }
    // }


    // for (int i = 1; i < obstacleGrid.size(); i++) {
    //     for (int j = 1; j < obstacleGrid[0].size(); j++) {
    //         if (obstacleGrid[i][j] != -1) {
    //             obstacleGrid[i][j] = obstacleGrid[i-1][j] + obstacleGrid[i][j-1];
    //         } else {
    //             obstacleGrid[i][j] = 0;
    //         }   
    //     }
    // }

    // for (int i = 0; i < obstacleGrid.size(); i++) {
    //     for (int j = 0; j < obstacleGrid[0].size(); j++) {
    //         cout << obstacleGrid[i][j] << " ";
    //     }
    //     cout << " " << endl;
    // }

    int m = obstacleGrid.size();
    int n = obstacleGrid[0].size();
    vector<long> dp(n);
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (obstacleGrid[i][j]) {
                dp[j] = 0;
            } else if (i == 0 && j == 0) {
                dp[j] = 1;
            } else if (i == 0) {
                dp[j] = dp[j-1];
            } else if (j == 0) {
                dp[j] = dp[j];
            } else {
                dp[j] += dp[j-1];
            }
        }
    }
    cout << dp[n-1] << endl;


    return 0;
}