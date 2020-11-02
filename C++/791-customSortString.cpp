#include <string>
#include <vector>

using namespace std;

string customSortString(string S, string T) {
    string res = "";
    vector<int> mp(26);
    for (auto c : T) mp[c - 'a']++;
    for (auto c : S) {
        while (mp[c - 'a']--) res.push_back(c);
    }
    for (int i = 0; i < 26; i++) {
        while (mp[i]-- > 0) res.push_back(i + 'a');
    }
    return res;
}