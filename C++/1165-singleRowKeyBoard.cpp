class Solution {
public:
    int calculateTime(string keyboard, string word) {
        if (keyboard.empty() || word.empty()) return 0;
        int res = find(keyboard.begin(), keyboard.end(), word[0]) - keyboard.begin();
        for (int i = 1; i < word.size(); i++) {
            int pos = find(keyboard.begin(), keyboard.end(), word[i - 1]) - keyboard.begin();
            int index = find(keyboard.begin(), keyboard.end(), word[i]) - keyboard.begin();
            res += abs(pos - index);
        }
        return res;
    }
};