#include <iostream>
#include <string>

using namespace std;

string longestPalindrome(string s) {
    if (s.size() <= 1) {
        return s;
    }
    int maxIdx = 0;
    int maxLength = 0;
    int i = 0;

    while (i < s.size()) {
        int start = i;
        int end = i;
        
        while (end + 1 < s.size() && s[end] == s[end+1]) {
            end++;
        }
        i = end + 1;

        while (start - 1 >= 0 && end + 1 < s.size() && s[start - 1] == s[end + 1]) {
            start--;
            end++;
        }

        int curLength = end - start + 1;
        if (curLength > maxLength) {
            maxIdx = start;
            maxLength = curLength;
        }
    }

    return s.substr(maxIdx, maxLength);
}

int main() {

    string answer;
    string s = "aba";
    answer = longestPalindrome(s);
    cout << answer << endl;

    return 0;
}