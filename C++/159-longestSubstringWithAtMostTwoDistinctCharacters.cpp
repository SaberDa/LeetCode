#include <iostream>
#include <string>
#include <unordered_set>

using namespace std;

int lengthOfLongestSubstringTwoDistinct(string s) {
    int i = 0, j = 0;
    int next = 0;
    int length = 0;
    unordered_set<char> set;
    while (j < s.size()) {
        j = i;
        while (j < s.size()) {
            if (set.size() == 1) {
                next = j;
            }
            set.insert(s[j]);
            if (set.size() > 2) {
                length = max(length, j - i);
                set.clear();
                i = next;
                break;
            }
            j++;
        }
    }
    length = max(length, j - i);
    return length;
}