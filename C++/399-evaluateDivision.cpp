#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

unordered_map<string, pair<string, double>> parent;

string findE(string a, double& value) {
    if (!parent.count(a)) {
        parent[a] = make_pair(a, 1.0);
        return a;
    } else {
        string p = parent[a].first;
        if (p == a) return p;
        else {
            value *= parent[a].second;
            return findE(p, value);
        }
    }
}

void unionE(string a, string b, double value) {
    double av = 1.0, bv = 1.0;
    string pa = findE(a, av);
    string pb = findE(b, bv);
    if (pa != pb) {
        parent[pb].first = pa;
        parent[pb].second = av * value / bv;
    }
}

vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
    for (int i = 0; i < values.size(); i++) {
        unionE(equations[i][0], equations[i][1], values[i]);
    }
    vector<double> ans;
    for (int i = 0; i < queries.size(); i++) {
        string a = queries[i][0];
        string b = queries[i][1];
        if (parent.find(a) == parent.end() || parent.find(b) == parent.end()) ans.push_back(-1.0);
        else {
            double av = 1.0, bv = 1.0;
            string pa = findE(a, av);
            string pb = findE(b, bv);
            if (pa != pb) ans.push_back(-1.0);
            else ans.push_back(bv / av);
        }
    }
    return ans;
}