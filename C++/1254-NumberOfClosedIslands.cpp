class Solution {
public:

    bool helper(vector<vector<int>> &grid, vector<vector<int>> &visited, int r, int c, int m, int n) {
        if (r < 0 || c < 0 || r >= m || c >= n) return false;
        if (grid[r][c] == 1 || visited[r][c]) return true;
        visited[r][c] = 1;
        bool right = helper(grid, visited, r + 1, c, m, n);
        bool left = helper(grid, visited, r - 1, c, m, n);
        bool up = helper(grid, visited, r, c + 1, m, n);
        bool bottom = helper(grid, visited, r, c - 1, m, n);
        return right && left && up && bottom;
    }

    int closedIsland(vector<vector<int>> &grid) {
        if (grid.empty()) return 0;
        int m = grid.size(), n = grid[0].size();
        vector<vector<int>> visited(m, vector<int>(n, 0));
        int res = 0;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 0 && !visited[i][j]) {
                    bool judge = helper(grid, visited, i, j, m, n);
                    if (judge) res++;
                }
            }
        }
        return res;
    }
};