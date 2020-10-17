#include <vector>
#include <string>

using namespace std;

bool isVowels(char c) {
    if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u') return true;
    return false;
}

string reverseVowels(string s) {
    if (s.empty()) return "";
    int l = 0, r = s.size() - 1;
    while (l <= r) {
        if (isVowels(tolower(s[l])) && isVowels(tolower(s[r]))) {
            char temp = s[l];
            s[l] = s[r];
            s[r] = temp;
            l++, r--;
        } else if (isVowels(tolower(s[l])) && !isVowels(tolower(s[r]))) {
            r--;
        } else {
            l++;
        }
    }
    return s;
}