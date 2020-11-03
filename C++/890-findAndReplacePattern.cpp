#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

string helper(string s) {
    unordered_map<char, char> mp;
    string res = "";
    char c = 'a';
    for (auto x : s) {
        if (!mp.count(x)) mp[x] = c++;
    }
    for (auto x : s) res.push_back(mp[x]);
    return res;
}

vector<string> findAndReplacePattern(vector<string>& words, string pattern) {
    vector<string> res;
    string temp = helper(pattern);
    for (auto s : words) {
        if (helper(s) == temp) res.push_back(s);
    }
    return res;
}