#include <iostream>
#include <vector>

using namespace std;

bool canFinish(int numCourse, vector<vector<int>>& prerequisites) {
    vector<int> indegree(numCourse);
    vector<vector<int>> graph(numCourse);
    for (int i = 0; i < prerequisites.size(); i++) {
        graph[prerequisites[i][1]].push_back(prerequisites[i][0]);
        indegree[prerequisites[i][0]]++;
    }
    for (int i = 0; i < numCourse; i++) {
        int j = 0;
        for (; j < numCourse; j++) {
            if (indegree[j] == 0) break;
        }
        if (j == numCourse) {
            return false;
        }
        indegree[j] = -1;
        for (auto x : graph[j]) {
            indegree[x]--;
        }
    }
    return true;
}