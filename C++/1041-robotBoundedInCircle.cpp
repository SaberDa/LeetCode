#include <iostream>
#include <vector>

using namespace std;

bool isRobotBounded(string instructions) {
    int x = 0, y = 0, i = 0;
    vector<vector<int>> d = {{0,1}, {1,0}, {0,-1}, {-1,0}};
    for (auto c : instructions) {
        if (c == 'L') {
            i = (i + 1) % 4;
        } else if (c == 'R') {
            i = (i + 3) % 4;
        } else {
            x += d[i][0];
            y += d[i][1];
        }
    }
    return x == 0 && y == 0 || i > 0;
}