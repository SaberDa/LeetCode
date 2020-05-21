#include <iostream>
#include <string>

using namespace std;

int lengthOfLastWord(string s) {
    if (s.empty()) {
        return 0;
    }
    int n = s.size();
    int count = 0;
    int cur = n - 1;
    while (cur >= 0 && s[cur] == ' ') {
        cur--;
    }
    while (cur >= 0 && s[cur] != ' ') {
        count++;
        cur--;
    }
    return count;
}