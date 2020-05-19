#include <iostream>
#include <vector>
#include <queue>

using namespace std;

bool isBipartite(vector<vector<int>>& graph) {
    int n = graph.size();
    vector<int> color(n, 0);
    for (int i = 0; i < n; i++) {
        if (color[i] != 0) {
            continue;
        }
        color[i] = 1;
        queue<int> q;
        q.push(i);
        while (!q.empty()) {
            int t = q.front();
            q.pop();
            for (auto &x : graph[t]) {
                if (color[x] == 0) {
                    color[x] = -color[t];
                    q.push(x);
                } else if (color[x] == color[t]) {
                    return false;
                }
            }
        }
    }
    return true;
}

bool DFS(vector<vector<int>>& graph, vector<int>& color, int c, int i) {
    if (color[i] != 0) {
        return color[i] == c;
    }
    color[i] = c;
    for (auto x :graph[i]) {
        if (!DFS(graph, color, -c, x)) {
            return false;
        }
    }
    return true;
}

bool isBipartiteDFS(vector<vector<int>>& graph) {
    int n = graph.size();
    vector<int> color(n, 0);
    for (int i = 0; i < n; i++) {
        if (color[i] == 0 && !DFS(graph, color, 1, i)) {
            return false;
        }
    }
    return true;
}