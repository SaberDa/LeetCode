#include <vector>

using namespace std;

bool judge(string s, string t) {
    if (s.size() > t.size()) return false;
    int i = 0, j = 0;
    int m = s.size(), n = t.size();
    while (i < m) {
        if (s[i] != t[j]) return false;
        int count1 = 1, count2 = 1;
        while (i + 1 < m && s[i] == s[i + 1]) {
            i++;
            count1++;
        }
        while (j + 1 < n && t[j] == t[j + 1]) {
            j++;
            count2++;
        }
        i++, j++;
        if (count1 == count2 || (count1 < count2 && count2 >= 3)) {
            continue;
        } else return false;
    }
    return i == m && j == n;
}

int expressiveWords(string S, vector<string>& words) {
    int res = 0;
    for (auto s : words) {
        if (judge(s, S)) res++;
    }
    return res;
}