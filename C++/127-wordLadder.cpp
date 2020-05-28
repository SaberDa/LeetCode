#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
    unordered_set<string> s1;
    unordered_set<string> s2;
    unordered_set<string> dict(wordList.begin(), wordList.end());
    if (dict.count(endWord) == 0) {
        return 0;
    }
    int length = beginWord.size();
    int res = 0;
    s1.insert(beginWord);
    s2.insert(endWord);
    while (!s1.empty() && !s2.empty()) {
        res++;
        if (s1.size() > s1.size()) {
            swap(s1, s2);
        }
        unordered_set<string> cur;
        for (auto w : s1) {
            for (int i = 0; i < length; i++) {
                char temp = w[i];
                for (char x = 'a'; x <= 'z'; x++) {
                    w[i] = x;
                    if (s2.count(w)) {
                        return res + 1;
                    }
                    if (dict.count(w) == 0) {
                        continue;
                    }
                    dict.erase(w);
                    cur.insert(w);
                }
                w[i] = temp;
            }
        }
        s1 = cur;
    }
    return 0;
}