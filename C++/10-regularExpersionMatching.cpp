#include <iostream>
#include <string>

using namespace std;

/*

T[i][j] =  T[i-1][j-1],   if (s[i] == p[j]) || (p[j] == '.')
           T[i][j-2],     if '*' represent && p[j] == '*'
           T[i-1][j],     if (s[i] == p[j-1]) || (p[j-1] == '.') && p[j] == '*'

*/



bool isMatch(string s, string p) {
    if (p.empty()) {
        return s.empty();
    }

    bool res[s.length()+1][p.length()+1];
    res[0][0] = true;

    for (int j = 1; j < p.length()+1; j++) {
        if (p[j-1] == '*') {
            res[0][j] = res[0][j-2];
        } else {
            res[0][j] = false;
        }
    }

    for (int i = 1; i < s.length()+1; i++) {
        res[i][0] = false;
    }

    for (int i = 1; i < s.length()+1; i++) {
        for (int j = 1; j < p.length() + 1; j++) {
            if (s[i-1] == p[j-1] || p[j-1] == '.') {
                res[i][j] = res[i-1][j-1];
            } else if (p[j-1] == '*') {
                res[i][j] = res[i][j-2];
                if (s[i-1] == p[j-2] || p[j-2] == '.') {
                    res[i][j] = res[i][j] | res[i-1][j];
                }
            } else {
                res[i][j] = false;
            }
        }
    }

    return res[s.length()][p.length()];
}

int main() {
    cout << isMatch("ab", ".*") << endl;
    return 0;
}