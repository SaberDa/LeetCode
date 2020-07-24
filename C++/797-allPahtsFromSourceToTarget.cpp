#include <iostream>
#include <vector>
#include <deque>

using namespace std;

vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
    vector<vector<int>> res;
    deque<vector<int>> cur;
    int target = graph.size() - 1;
    cur.push_back({0});
    while (!cur.empty()) {
        auto temp = cur.front();
        cur.pop_front();
        if (temp.back() == target) res.push_back(temp);
        else {
            for (auto it : graph[temp.back()]) {
                vector<int> t(temp.begin(), temp.end());
                t.push_back(it);
                cur.push_back(t);
            }
        }
    }
    return res;
}