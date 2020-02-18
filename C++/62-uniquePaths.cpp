#include <iostream>
#include <vector>

using namespace std;

int main() {

    int m, n;
    m = 7, n =3;
    vector<vector<int>> nums(m, vector<int>(n, 0));
    for (int i = 0; i < m; i++) {
        nums[i][0] = 1;
    }
    for (int i = 0; i < n; i++) {
        nums[0][i] = 1;
    }

    for (int i = 1; i < m; i++) {
        for (int j = 1; j < n; j++) {
            nums[i][j] = nums[i-1][j] + nums[i][j-1];
        }
    }

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            cout << nums[i][j] << " ";
        }
        cout << " " << endl;
    }

    cout << nums[m-1][n-1] << endl;

    return 0;
}