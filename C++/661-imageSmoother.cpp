#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> imageSmoother(vector<vector<int>>& M) {
    if (M.empty()) return M;
    int m = M.size(), n = M[0].size();
    vector<vector<int>> res(m, vector<int>(n, 0));
    vector<vector<int>> dir({{-1,-1}, {0,-1}, {1,-1}, {-1,0}, {0,0}, {1,0}, {-1,1}, {0,1}, {1,1}});
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            int sum = 0, count = 0;
            for (auto c : dir) {
                int l = i + c[0], h = j + c[1];
                if (l >= 0 && l < m && h >= 0 && h < n) {
                    count++;
                    sum += M[l][h];
                }
            }
            res[i][j] = sum / count;
        }
    }
    return res;
}