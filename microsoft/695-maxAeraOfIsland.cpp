#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> d = {{1,0}, {0,1}, {-1,0}, {0,-1}};

void DFS(vector<vector<int>>& grid, int r, int c, int m, int n, int& area) {
    if (r < 0 || c < 0 || r == m || c == n || !grid[r][c]) return;
    area++;
    grid[r][c] = 0;
    for (int i = 0; i < 4; i++) DFS(grid, r + d[i][0], c + d[i][1], m, n, area);
}

int maxAreaOfIsland(vector<vector<int>>& grid) {
    if (grid.empty()) return 0;
    int m = grid.size(), n = grid[0].size();
    int res = 0;
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (grid[i][j]) {
                int temp = 0;
                DFS(grid, i, j, m, n, temp);
                res = max(res, temp);
            }
        }
    }
    return res;
}