#include <iostream>
#include <vector>

using namespace std;

bool judge(string s) {
    int i = 0, j = s.size() - 1;
    while (i < j) {
        if (s[i++] != s[j--]) return false;
    }
    return true;
}

int countSubstrings(string s) {
    int count = 0;
    if (s.empty()) return count;
    for (int i = 0; i < s.size(); i++) {
        for (int j = i; j < s.size(); j++) {
            if (judge(s.substr(i, j - i + 1))) count++;
        }
    }
    return count;
}