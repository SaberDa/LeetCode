class Solution {
public:
    bool areAlmostEqual(string s1, string s2) {
        if (s1 == s2) return true;
        int x, y, count = 0;
        for (int i = 0; i < s1.size(); i++) {
            if (s1[i] != s2[i]) {
                count++;
                if (count > 2) return false;
                if (count == 1) x = i;
                if (count == 2) y = i;
            }
        }
        if (count != 2) return false;
        return s1[x] == s2[y] && s1[y] == s2[x];
    }
};