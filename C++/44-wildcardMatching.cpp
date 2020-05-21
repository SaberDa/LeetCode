#include <iostream>

using namespace std;

bool isMatch(string s, string p) {
    int i = 0;
    int j = 0;
    int ss = 0;
    int star = -1;
    while (i < s.size()) {
        if (j < p.size() && (p[j] == '?' || s[i] == p[j])) {
            i++;
            j++;
        } else if (j < p.size() && p[j] == '*') {
            star = j;
            ss = i;
            j++;
        } else if (star != -1) {
            j = star + 1;
            ss++;
            i = ss;
        } else {
            return false;
        }
    }
    while (j < p.size() && p[j] == '*') {
        j++;
    }
    return j == p.size();
}