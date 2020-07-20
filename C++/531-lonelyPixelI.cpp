#include <iostream>
#include <vector>

using namespace std;

int findLonelyPixel(vector<vector<char>>& picture) {
    int res = 0;
    int m = picture.size(), n = picture[0].size();
    for (int i = 0; i < m; i++) {
        bool flag = true;
        for (int j = 0; j < n && flag; j++) {
            if (picture[i][j] == 'B') {
                flag = false;
                int r = 0, c = j + 1;
                for (; r < m; r++) if (r != i && picture[r][j] == 'B') break;
                for (; c < n; c++) if (picture[i][c] == 'B') break;
                if (r == m && c == n) res++;
            } 
        }
    }
    return res;
}