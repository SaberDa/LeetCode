#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<vector<int>> indexPairs(string text, vector<string>& words) {
    vector<vector<int>> res;
    for (auto s : words) {
        int p = text.find(s, 0);
        while (p != string::npos) {
            res.push_back({p, (int)(p + s.size() - 1)});
            p = text.find(s, p + 1);
        }
    }
    sort(res.begin(), res.end()); 
    return res;
}