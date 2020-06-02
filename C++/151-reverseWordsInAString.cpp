#include <iostream>
#include <string>
#include <vector>

using namespace std;

string reverseWords(string s) {
    reverse(s.begin(), s.end());
    int i = 0, j = 0;
    while (i != s.size()) {
        while (j < s.size() && s[j] != ' ') {
            j++;
        }
        reverse(s.begin() + i, s.begin() + j);
        i = j;
        while (i < s.size() && s[i] == ' ') {
            i++, j++;
        }
    }
    i = 0, j = 0;
    while (j < s.size()) {
        bool word = false;
        while (j < s.size() && s[j] == ' ') {
            word = true;
            j++;
        }
        if (j == s.size()) {
            break;
        }
        if (word && i > 0) {
            s[i] = ' ';
            i++;
        }
        s[i++] = s[j++];
    }
    s.substr(0, i);
    return s;
}