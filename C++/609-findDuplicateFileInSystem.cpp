#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

vector<vector<string>> findDuplicate(vector<string>& paths) {
    unordered_map<string, vector<string>> mp;
    vector<vector<string>> res;
    if (paths.empty()) return res;
    for (auto path : paths) {
        stringstream ss(path);
        string root;
        string s;
        getline(ss, root, ' ');
        while (getline(ss, s, ' ')) {
            string fileName = root + '/' + s.substr(0, s.find('('));
            string fileContent = s.substr(s.find('(') + 1, s.find(')') - s.find('(') - 1);
            mp[fileContent].push_back(fileName);
        }
    }
    for (auto it : mp) {
        if (it.second.size() > 1) res.push_back(it.second);
    }
    return res;
}