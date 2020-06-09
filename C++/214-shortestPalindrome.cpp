#include <iostream>
#include <string>

using namespace std;

string shortestPalindrome(string s) {
    int i = 0, n = s.size();
    for (int j = n - 1; j >= 0; j--) {
        if (s[i] == s[j]) i++;
    }
    if (i == n) return s;
    string t = s.substr(i, n);
    reverse(t.begin(), t.end());
    return t + shortestPalindrome(s.substr(0, i)) + s.substr(i);
}