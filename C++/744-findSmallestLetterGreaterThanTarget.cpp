#include <iostream>
#include <vector>

using namespace std;

char nextGreatestLetter(vector<char>& letters, char target) {
    int l = 0, r = letters.size() - 1;
    if (target >= letters.back()) return letters[0];
    while (l <= r) {
        int m = l + (r - l) / 2;
        if (letters[m] <= target) l = m + 1;
        else r = m - 1;
    }
    return letters[l];
}