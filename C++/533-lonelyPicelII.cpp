#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

int findBlackPixel(vector<vector<char>>& picture, int N) {
    int res = 0;
    int m = picture.size(), n = picture[0].size();
    vector<int> row(m, 0), col(n, 0);
    unordered_map<string, int> mp;
    vector<string> temp;
    for (int i = 0; i < m; i++) {
        string s = "";
        for (int j = 0; j < n; j++) {
            if (picture[i][j] == 'B') {
                row[i]++;
                col[j]++;
            }
            s.push_back(picture[i][j]);
        }
        mp[s]++;
        temp.push_back(s);
    }
    for (int i = 0; i < m; i++) {
        if (row[i] == N && mp[temp[i]] == N) {
            for (int j = 0; j < n; j++) {
                if (picture[i][j] == 'B' && col[j] == N) res++;
            }
        }
    }
    return res;
}