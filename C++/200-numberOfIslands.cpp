#include <iostream>
#include <vector>

using namespace std;

void DFS(vector<vector<char>>& grid, int r, int c, int m, int n) {
    if (r < 0 || c < 0 || r == m || c == n || grid[r][c] == '0') {
        return;
    }
    grid[r][c] = '0';
    DFS(grid, r, c + 1, m, n);
    DFS(grid, r, c - 1, m, n);
    DFS(grid, r + 1, c, m, n);
    DFS(grid, r - 1, c, m, n);
}


int numIslands(vector<vector<char>>& grid) {
    if (grid.empty()) {
        return 0;
    }
    int res = 0;
    int m = grid.size();
    int n = grid[0].size();
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (grid[i][j] == '1') {
                res++;
                DFS(grid, i, j, m, n);
            }
        }
    }
    return res;
}