#include <iostream>
#include <string>
#include <vector>

using namespace std;

string findContestMatch(int n) {
    vector<string> res;
    for (int i = 1; i <= n; i++) {
        res.push_back(to_string(i));
    }
    while (res.size() != 1) {
        int n = res.size();
        for (int i = 0; i < n / 2; i++) {
            res[i] = '(' + res[i] + ',' + res.back() + ')';
            res.pop_back();
        }
    }
    return res[0];
}