#include <iostream>
#include <vector>

using namespace std;

// int main() {

//     int rowIndex = 3;
//     vector<vector<int>> ans(rowIndex+1);
//     if (rowIndex == 0 || rowIndex > 34) return 0;
//     ans[0].push_back(1);
//     for (int i = 1; i <= rowIndex; i++) {
//         ans[i].push_back(1);
//         for (int j = 1; j < i; j++) {
//             ans[i].push_back(ans[i-1][j-1] + ans[i-1][j]);
//         }
//         ans[i].push_back(1);
//     }

//     vector<int> res;
//     res = ans[ans.size()-1];


//     return 0;
// }

int main() {

    int rowIndex = 3;
    int n = rowIndex;
    int d = 1;
    vector<int> res = {1};
    int temp = 1;
    while (n > 0) {
        res.push_back(temp = temp * n / d);
        n--;
        d++;
    }
    for (auto x : res) {
        cout << x << endl;
    }

    return 0;
}