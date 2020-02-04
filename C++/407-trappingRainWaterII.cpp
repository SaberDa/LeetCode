#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <climits>

using namespace std;

struct cell {
    int i;
    int j;
    int height;
    cell(int _i, int _j, int _height) {
        i = _i;
        j = _j;
        height = _height;
    }
};

struct compare {
    bool operator() (cell &c1, cell &c2) {
        return c1.height > c2.height;
    }
};

static inline bool isMoveValid(const int i, const int j, const int rows, const int cols) {
    if (i >= 0 && i < rows && j >=0 && j < cols) {
        return true;
    }
    return false;
}

int main() {

    vector<vector<int>> heightMap;
    heightMap.push_back({1, 4, 3, 1, 3, 2});
    heightMap.push_back({3, 2, 1, 3, 2, 4});
    heightMap.push_back({2, 3, 3, 2, 3, 1});

    if (heightMap.empty()) {
        return 0;
    }
    int rows = heightMap.size();
    int cols = heightMap[0].size();
    priority_queue<cell, vector<cell>, compare> pq;
    vector<vector<bool>> wasVisted(rows, vector<bool>(cols, false));

    int range = INT_MIN;
    int res = 0;

    for (int i = 0; i < rows; i++) {
        if (!wasVisted[i][cols-1]) {
            wasVisted[i][cols-1] = true;
            cell c(i, cols-1, heightMap[i][cols-1]);
            pq.push(c);
        }
        if (!wasVisted[i][0]) {
            wasVisted[i][0] = true;
            cell c(i, 0, heightMap[i][0]);
            pq.push(c);
        }
    }

    for (int j = 0; j < cols; j++) {
        if (!wasVisted[0][j]) {
            wasVisted[0][j] = true;
            cell c(0, j, heightMap[0][j]);
            pq.push(c);
        }
        if (!wasVisted[rows-1][j]) {
            wasVisted[rows-1][j] = true;
            cell c(rows-1, j, heightMap[rows-1][j]);
            pq.push(c);
        }
    }

    while (!pq.empty()) {
        cell top = pq.top();
        pq.pop();
        range = max(range, top.height);
        if (isMoveValid(top.i+1, top.j, rows, cols) 
            && !wasVisted[top.i+1][top.j]) {
                cell c(top.i+1, top.j, heightMap[top.i+1][top.j]);
                wasVisted[top.i+1][top.j] = true;
                pq.push(c);
                if (c.height < range) {
                    res += range - c.height;
                }
            }
        if (isMoveValid(top.i-1, top.j, rows, cols) 
            && !wasVisted[top.i-1][top.j]) {
                wasVisted[top.i-1][top.j] = true;
                cell c(top.i-1, top.j, heightMap[top.i-1][top.j]);
                pq.push(c);
                if (c.height < range) {
                    res += range - c.height;
                }
            } 
        if (isMoveValid(top.i, top.j+1, rows, cols)
            && !wasVisted[top.i][top.j+1]) {
                wasVisted[top.i][top.j+1] = true;
                cell c(top.i, top.j+1, heightMap[top.i][top.j+1]);
                pq.push(c);
                if (c.height < range) {
                    res += range - c.height;
                }
            }
        if (isMoveValid(top.i, top.j-1, rows, cols)
            && !wasVisted[top.i][top.j-1]) {
                wasVisted[top.i][top.j-1] = true;
                cell c(top.i, top.j-1, heightMap[top.i][top.j-1]);
                pq.push(c);
                if (c.height < range) {
                    res += range - c.height;
                }
            }
    }

    cout << res << endl;

    return 0;
}
