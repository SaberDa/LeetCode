#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

int compress(vector<char>& chars) {
    if (chars.empty()) return 0;
    int l = 0, i = 0;
    for (int j = 0; j < chars.size(); j++) {
        if (j + 1 == chars.size() || chars[j + 1] != chars[j]) {
            chars[l++] = chars[j];
            if (i < j) {
                for (auto c : to_string(j - i + 1)) chars[l++] = c;
            }
            i = j + 1;
        }
    }
    return l;
}