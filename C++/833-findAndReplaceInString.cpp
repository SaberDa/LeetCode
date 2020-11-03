#include <string>
#include <vector>
#include <map>

using namespace std;

string findReplaceString(string S, vector<int>& indexes, vector<string>& sources, vector<string>& targets) {
    map<int, pair<string, string>> mp;
    for (int i = 0; i < indexes.size(); i++) {
        mp[indexes[i]] = {sources[i], targets[i]};
    }
    string res = "";
    for (int i = 0; i < S.size(); ) {
        if (mp.count(i) && S.find(mp[i].first, i) == i) {
            res.append(mp[i].second);
            i += mp[i].first.size();
        } else {
            res.push_back(S[i++]);
        }
    }
    return res;
}
