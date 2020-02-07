#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include <queue>

using namespace std;

int main() {

    string s = "tree";

    string res;
    unordered_map<char, int> m;
    for (auto i : s) {
        m[i]++;
    }
    auto comp = [](pair<int, char>& a, pair<int, char>& b){return a.first < b.first;};
    priority_queue<pair<int, char>, vector<pair<int, char>>, decltype(comp)> pq(comp);
    for (auto i : m) {
        pq.push({i.second, i.first});
    }
    while (!pq.empty()) {
        auto p = pq.top();
        pq.pop();
        while (p.first) {
            res.push_back(p.second);
            p.first--;
        }
    }

    cout << res << endl;

    return 0;
}