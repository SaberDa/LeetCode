// use median
// BFS exceed time
class Solution {
public:
    int minTotalDistance(vector<vector<int>>& grid) {
        vector<int> row;
        vector<int> col;
        if (grid.empty()) {
            return 0;
        }
        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[0].size(); j++) {
                if (grid[i][j]) {
                    row.push_back(i);
                    col.push_back(j);
                }
            }
        }
        int maxRow = row[row.size() / 2];
        nth_element(col.begin(), col.begin() + col.size() / 2, col.end());
        int maxCol = col[col.size() / 2];
        int distance = 0;
        for (auto i : row) {
            distance += abs(maxRow - i);
        }
        for (auto i : col) {
            distance += abs(maxCol - i);
        }
        return distance;
    }
};
