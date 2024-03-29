#include <iostream>
#include <string>

using namespace std;

bool isSequence(string s, string t) {
    int i = 0, j = 0;
    while (i < s.size() && j < t.size()) {
        if (s[i] == t[j]) i++, j++;
        else j++;
    }
    return (i == s.size()) ? true : false;
}