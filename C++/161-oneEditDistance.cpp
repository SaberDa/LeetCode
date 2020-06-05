#include <iostream>
#include <string>
#include <cmath>

using namespace std;

bool isOneEditDistance(string s, string t) {
    int diff = abs((int)s.size() - (int)t.size());
    if (diff > 1) {
        return false;
    }
    int dis = 0;
    if (diff == 0) {
        for (int i = 0; i < s.size(); i++) {
            if (s[i] != t[i]) {
                dis++;
            }
        }
    } else {
        int i = 0;
        int j = 0;
        while (i < s.size() && j < t.size()) {
            if (s[i] != t[j]) {
                dis++;
                s.size() > t.size() ? i++ : j++;
            } else {
                i++;
                j++;
            }
        }
        if (i != s.size() || j != t.size()) {
            dis++;
        }
    }
    return dis == 1;
}