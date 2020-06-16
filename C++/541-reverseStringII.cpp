#include <iostream>
#include <string>

using namespace std;

string reverseStr(string s, int k) {
    if (s.empty() || k == 0) return s;
    for (int j = 0; j < s.size();) {
        if (j + k < s.size()) reverse(s.begin() + j, s.begin() + j + k);
        else reverse(s.begin() + j, s.end());
        j += 2 * k;
    }
    return s;
}