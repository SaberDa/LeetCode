#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

int smallestCommonElement(vector<vector<int>>& mat) {
    // hash map
    // unordered_map<int, int> mp;
    // for (auto x : mat) 
    //     for (auto y : x) {
    //         mp[y]++;
    //         if (mp[y] >= mat.size()) return y;
    //     }
    // return -1;

    int m = mat.size(), n = mat[0].size();
    for (int j = 0; j < n; j++) {
        bool flag = true;
        for (int i = 0; i < m && flag; i++) {
            flag = binary_search(mat[i].begin(), mat[i].end(), mat[0][j]);
        }
        if (flag) return mat[0][j];
    }
    return -1;
}