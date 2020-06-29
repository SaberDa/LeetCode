#include <iostream>
#include <vector>

using namespace std;

int findJudge(int N, vector<vector<int>>& trust) {
    vector<int> judge(N + 1);
    for (auto x : trust) {
        judge[x[0]]--;
        judge[x[1]]++;
    }
    for (int i = 1; i <= N; i++) {
        if (judge[i] == N - 1) return i;
    }
    return -1;
}