#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <queue>

using namespace std;

struct Node {
    char val;
    int ind;
    unordered_map<char, Node*> next{};
    Node(char c) : val(c), ind(0) {}
};

string alienOrder(vector<string>& words) {
    unordered_map<char, Node*> g;
    for (int i = 0; i < words.size(); i++) {
        for (int j = 0; j < words[i].size(); j++) {
            char c = words[i][j];
            if (g.find(c) == g.end()) {
                g[c] = new Node(c);
            }
        }
    }

    for (int i = 1; i < words.size(); i++) {
        int preLen = words[i-1].size();
        int curLen = words[i].size();
        int j = 0;
        while (j < preLen && j < curLen && words[i-1][j] == words[i][j]) {
            j++;
        }
        if (j < preLen && j == curLen) {
            return "";
        }
        if (j < preLen && j < curLen) {
            char fc = words[i-1][j];
            char sc = words[i][j];
            if (g[fc]->next.find(sc) == g[fc]->next.end()) {
                g[fc]->next[sc] = g[sc];
                g[sc]->ind++;
            }
        }
    }

    queue<Node*> q{};
    for (auto& pa : g) {
        if (pa.second->ind == 0) {
            q.push(pa.second);
        }
    }

    int i = 0;
    int len = q.size();
    int sum = g.size();
    string res = "";
    while (i < len && !q.empty()) {
        auto pa = q.front();
        q.pop();
        res += pa->val;
        for (auto& subnode : pa->next) {
            subnode.second->ind--;
            if (subnode.second->ind == 0) {
                q.push(subnode.second);
            }
        }
        if (i == len - 1) {
            i = 0;
            len = q.size();
        }
    }

    return (res.size() == sum) ? res : "";
}