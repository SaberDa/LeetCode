#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> d = {{0,1}, {1,0}, {0,-1}, {-1,0}};

void helper(vector<vector<int>>& grid, int r, int c, int m, int n, int &area) {
    if (r < 0 || c < 0 || r == m || c == n || !grid[r][c]) return;
    area++;
    grid[r][c] = 0;
    for (int i = 0; i < 4; i++) helper(grid, r + d[i][0], c + d[i][1], m, n, area);
}

int maxAreaOfIsland(vector<vector<int>>& grid) {
    if (grid.empty()) return 0;
    int area = 0;
    int m = grid.size(), n = grid[0].size();
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (grid[i][j] == 1) {
                int temp = 0;
                helper(grid, i, j, m, n, temp);
                area = max(area, temp);
            }
        }
    }
    return area;
}