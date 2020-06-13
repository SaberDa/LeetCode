#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

int islandPerimeter(vector<vector<int>>& grid) {
    if (grid.empty()) return 0;
    int land = 0, flag = 0;
    for (int i = 0; i < grid.size(); i++) {
        for (int j = 0; j < grid[0].size(); j++) {
            if (grid[i][j] == 0) continue;
            land++;
            if (i != 0 && grid[i - 1][j] == 1) flag++;
            if (j != 0 && grid[i][j - 1] == 1) flag++;
        }
    }
    return land * 4 - flag * 2;
}