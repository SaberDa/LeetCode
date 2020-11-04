#include <vector>
#include <string>
#include <unordered_map>
#include <unordered_set>

using namespace std;

string tolow(string s) {
    for (auto &c : s) c = tolower(c);
    return s;
}

string devol(string s) {
    s = tolow(s);
    for (auto &c : s) {
        if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u') {
            c = '#';
        }
    }
    return s;
}

vector<string> spellchecker(vector<string>& wordlist, vector<string>& queries) {
    unordered_set<string> set(wordlist.begin(), wordlist.end());
    unordered_map<string, string> cap, vowel;
    for (auto s : wordlist) {
        string lower = tolow(s), devowel = devol(s);
        cap.insert({lower, s});
        vowel.insert({devowel, s});
    }
    for (int i = 0; i < queries.size(); i++) {
        if (set.count(queries[i])) continue;
        string lower = tolow(queries[i]), devowel = devol(queries[i]);
        if (cap.count(lower)) queries[i] = cap[lower];
        else if (vowel.count(devowel)) queries[i] = vowel[devowel];
        else queries[i] = "";
    }
    return queries;
}