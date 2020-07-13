#include <iostream>
#include <vector>
#include <unordered_map>
#include <deque>
#include <algorithm>
#include <numeric>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left, *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};


// BFS
vector<int> killProcess(vector<int>& pid, vector<int>& ppid, int kill) {
    if (pid.size() != ppid.size()) return vector<int>();
    vector<int> res;
    unordered_map<int, vector<int>> mp;
    for (int i = 0; i < pid.size(); i++) {
        mp[ppid[i]].push_back(pid[i]);
    }
    deque<int> cur, next;
    cur.push_back(kill);
    while (!cur.empty()) {
        int temp = cur.front();
        cur.pop_front();
        res.push_back(temp);
        for (auto x : mp[temp]) next.push_back(x);
        if (cur.empty()) swap(cur, next);
    }
    return res;
}

// Union Find

int find(vector<int>& parent, int c) {
    return (parent[c] == c) ? parent[c] : find(parent, parent[c]);
}

vector<int> killProcess(vector<int>& pid, vector<int>& ppid, int kill) {
    vector<int> res;
    if (pid.size() != ppid.size()) return res;
    int max = *max_element(pid.begin(), pid.end());
    vector<int> parent(max + 1);
    iota(parent.begin(), parent.end(), 0);
    for (int i = 0; i < pid.size(); i++) {
        if (pid[i] == kill) continue;
        int root1 = find(parent, pid[i]);
        int root2 = find(parent, ppid[i]);
        if (root1 != root2) parent[root1] = root2;
    }
    for (auto x : pid) {
        if (x == kill || find(parent, x) == kill) res.push_back(x);
    }
    return res;
}