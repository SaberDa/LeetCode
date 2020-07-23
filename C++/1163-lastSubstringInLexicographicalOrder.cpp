#include <iostream>
#include <string>

using namespace std;

string lastSubstring(string s) {
    int i = 0, pos;
    for (int j = 1; j < s.size(); j++) {
        for (pos = 0; pos + j < s.size(); pos++) {
            if (s[j + pos] == s[i + pos]) continue;
            i = s[j + pos] > s[i + pos] ? j : i;
            break;
        }
        if (j + pos == s.size()) break;
    }
    return s.substr(i);
}