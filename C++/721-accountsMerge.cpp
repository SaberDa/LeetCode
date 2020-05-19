#include <iostream>
#include <vector>
#include <unordered_map>
#include <string>
#include <algorithm>

using namespace std;

vector<int> parent;
int find(int x) {
    return (parent[x] == x) ? x : find(parent[x]);
}

vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
    int n = accounts.size();
    unordered_map<string, int> email;
    parent.resize(n, 0);

    for (int i = 0; i < accounts.size(); i++) {
        parent[i] = i;
        for (int j = 1; j < accounts[i].size(); j++) {
            if (email.find(accounts[i][j]) != email.end()) {
                int x = find(i);
                int y = find(email[accounts[i][j]]);
                if (y != x) {
                    parent[y] = x;
                }
            } else {
                email[accounts[i][j]] = i;
            }
        }
    }

    unordered_map<int, vector<string>> emailGroups;
    for (auto it = email.begin(); it != email.end(); it++) {
        int x = find(it->second);
        emailGroups[x].push_back(it->first);
    }

    vector<vector<string>> res;
    for (auto it = emailGroups.begin(); it != emailGroups.end(); it++) {
        vector<string> temp;
        sort(it->second.begin(), it->second.end());
        temp.push_back(accounts[it->first][0]);
        for (int i = 0; i < it->second.size(); i++) {
            temp.push_back(it->second[i]);
        }
        res.push_back(temp);
    }

    return res;
}