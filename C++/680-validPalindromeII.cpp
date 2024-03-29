#include <iostream>
#include <string>

using namespace std;

bool isValid(string s) {
    int i = 0, j = s.size() - 1;
    while (i <= j && s[i] == s[j]) {
        i++;
        j--;
    }
    return i > j;
}

bool validPallindrome(string s) {
    int i = 0;
    int j = s.size() - 1;
    while (i <= j && s[i] == s[j]) {
        i++;
        j--;
    }
    return i > j || isValid(s.substr(i, j - i)) || isValid(s.substr(i + 1, j - i));
}