#include <string>
#include <vector>
#include <unordered_map>
#include <sstream>

using namespace std;

vector<string> subdomainVisits(vector<string> &cpdomains) {
    unordered_map<string, int> mp;
    for (auto s : cpdomains) {
        int idx = s.find(' ');
        int count = stoi(s.substr(0, idx));
        while (idx != string::npos) {
            mp[s.substr(idx + 1)] += count;
            idx = s.find('.', idx + 1);
        }
    }
    vector<string> res;
    for (auto x : mp) {
        res.push_back(to_string(x.second) + ' ' + x.first);
    }
    return res;
}