#include <iostream>
#include <stack>
#include <vector>

using namespace std;

vector<int> dailyTemperature(vector<int>& T) {
    if (T.empty()) return vector<int>();
    vector<int> res(T.size(), 0);
    stack<pair<int, int>> s;
    for (int i = 0; i < T.size(); i++) {
        while (!s.empty() && s.top().first < T[i]) {
            res[s.top().second] = i - s.top().second;
            s.pop();
        }
        if (i + 1 != T.size() && T[i + 1] > T[i]) res[i] = 1;
        else s.push({T[i], i});
    }
    return res;
}