#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

int maxRepOpt1(string text) {
    vector<int> mp(26, 0);
    for (auto c : text) mp[c - 'a']++;
    int m = text.size();
    int i = 0, c = 0;
    while (i < m) {
        char cur = text[i];
        int z = -1, j = i + 1, tc = 1;
        bool change = true;
        while (j < m) {
            if (tc == mp[cur - 'a']) break;
            if (cur == text[j]) tc++, j++;
            else {
                if (change) {
                    change = false;
                    z = j; 
                    tc++;
                    j++;
                } else break;
            }
        }
        c = max(c, tc);
        i = (z == -1) ? j + 1 : z;
    }
    return c;
}