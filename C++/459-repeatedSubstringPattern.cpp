#include <string>

using namespace std;

bool repeatedSubstringPattern(string s) {
    int size = s.size();
    for (int i = 1; i <= size / 2; i++) {
        if (size % i) continue;
        string temp = s.substr(0, i);
        bool flag = true;
        for (int j = i; j < size; j += temp.size()) {
            if (temp != s.substr(j, i)) {
                flag = false;
                break;
            }
        }
        if (flag) return true;
    }
    return false;
}