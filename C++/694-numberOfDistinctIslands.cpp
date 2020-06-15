#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

vector<vector<int>> d = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};

void DFS(vector<vector<int>>& grid, int r, int c, int m, int n, int& area) {
    if (r < 0 || c < 0 || r == m || c == n || !grid[r][c] || grid[r][c] == 2) return;
    area++;
    grid[r][c] = 2;
    for (int i = 0; i < 4; i++) DFS(grid, r + d[i][0], c + d[i][1], m, n, area);
}

void DFS(vector<vector<int>>& grid, int r, int c, int R, int C, int m, int n, int& S, vector<vector<int>>& visited) {
    if (r < 0 || c < 0 || r == m || c == n || R < 0 || C < 0 || R == m || C == n || visited[r][c]) return;
    if ((!grid[r][c] && !grid[R][C]) || grid[r][c] != grid[R][C]) return;
    S++;
    visited[r][c] = 1;
    for (int i = 0; i < 4; i++) DFS(gird, r + d[i][0], c + d[i][1], R + d[i][0], C + d[i][1], m, n, S, visited);
}

int numDistinctIslands(vector<vector<int>>& grid) {
    unordered_map<int, vector<vector<int>>> mp;
    int count = 0;
    int m = grid.size(), n = grid[0].size();
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (grid[i][j] == 1) {
                int area = 0;
                DFS(grid, i, j, m, n, area);
                bool equal = false;
                for (auto x : mp[area]) {
                    int S = 0;
                    vector<vector<int>> visited(m, vector<int>(n));
                    DFS(grid, i, j, x[0], x[1], m, n, S, visited);
                    if (S == area) {
                        equal = true;
                        break;
                    }
                }
                if (!equal) {
                    count++;
                    mp[area].push_back({i, j});
                }
            }
        }
    }
    return count;
}