#include <iostream>

using namespace std;

string getPermutation(int n, int k) {
    string s = "";
    string res = "";
    for (int i = 1; i <= n; i++) {
        s.push_back(i + '0');
    }
    string path = s;
    int count = 0;
    helper(s, n, k, 0, count, res, path);
    return res;
}

void helper(string& s, int n, int k, int pos, int& count, string& res, string& path) {
    if (count >= k || pos == n) {
        count++;
        if (count == k) {
            res = path;
        }
        return;
    }
    for (int i = 0; i < n; i++) {
        if (s[i] == '0') {
            continue;
        }
        path[pos] = s[i];
        s[i] = '0';
        helper(s, n, k, pos + 1, count, res, path);
        s[i] = path[pos];
    }
}

