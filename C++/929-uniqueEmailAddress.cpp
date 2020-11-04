#include <vector>
#include <string>
#include <unordered_map>

using namespace std;

int numUniqueEmails(vector<string> &emails) {
    unordered_map<string, int> mp;
    for (auto s : emails) {
        int i = 0, pos = s.find('@');
        string temp = "";
        while (i < pos) {
            if (s[i] == '+') break;
            else if (s[i] == '.') i++;
            else temp.push_back(s[i++]);
        }
        temp.append(s.substr(pos));
        mp[temp]++;
    }
    return mp.size();
}