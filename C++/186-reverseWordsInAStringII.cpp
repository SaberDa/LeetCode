#include <isotream>
#include <string>
#include <vector>

using namespace std;

void reverseWords(vector<char>& s) {
    if (s.empty()) {
        return;
    }
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
        if (i > 0 && word) {
            s[i] = ' ';
            i++;
        }
        s[i++] = s[j++];
    }
    for (int t = i; t < s.size(); t++) {
        s.erase(s.begin() + t);
    }
    return;
}