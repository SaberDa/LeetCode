#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

vector<string> reorderLogFiles(vector<string> &logs) {
    vector<string> cnt1, cnt2;
    unordered_map<string, string> mp;
    for (int i = 0; i < logs.size(); i++) {
        for (int j = 0; j < logs[i].size(); j++) {
            if (logs[i][j] == ' ') {
                if (isdigit(logs[i][j + 1])) cnt2.push_back(logs[i]);
                else cnt1.push_back(logs[i]);
                mp[logs[i]] = logs[i].substr(j + 1);
                break;
            } 
        }
    }
    auto comp = [&](string &a, string &b) {
        if (mp[a] == mp[b]) return a < b;
        return mp[a] < mp[b];
    };
    sort(cnt1.begin(), cnt1.end(), comp);
    for (auto s : cnt2) cnt1.push_back(s);
    return cnt1;
}