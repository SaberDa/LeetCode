#include <iostream>
#include <string>

using namespace std;

bool isNumber(string s) {
    if (s.length() == 0) {
        return false;
    }
    int i = 0;
    int n = s.length() - 1;
    bool e = false;
    bool dot = false;
    bool digit = false;

    // erase the ' '
    while (i < s.length() && s[i] == ' ') {
        i++;
    }
    while (n >= 0 && s[n] == ' ') {
        n--;
    }

    if (s[i] == '+' || s[i] == '-') {
        i++;
    }

    if (i > n) {
        return false;
    }

    for (; i <= n; i++) {
        if (isdigit(s[i])) {
            digit = true;
            continue;
        } else if (s[i] == 'e' && digit && i != n && !e) {
            e = true;
            if (s[i+1] == '+' || s[i+1] == '-') {
                if (i+1 == n) {
                    return false;
                } else {
                    i++;
                }
            }
        } else if (s[i] == '.' && !dot && !e) {
            dot = true;
        } else {
            return false;
        }
    }

    return digit;
}

int main() {
    cout << isNumber("2e10") << endl;
    return 0;
}