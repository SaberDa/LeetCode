#include <iostream>
#include <vector>

using namespace std;

void reverseString(vector<char>& s) {
    if (s.empty()) return;
    for (int i = 0, j = s.size() - 1; i < j; i++, j--) {
        swap(s[i], s[j]);
    }
    return;
}