#include <vector>
#include <string>
#include <unordered_map>

using namespace std;

string mostCommonWord(string paragraph, vector<string>& banned) {
    unordered_map<string, int> mp;
    for (int i = 0; i < paragraph.size(); ) {
        string temp = "";
        while (i < paragraph.size() && isalpha(paragraph[i])) temp.push_back(tolower(paragraph[i++]));
        while (i < paragraph.size() && !isalpha(paragraph[i])) i++;
        mp[temp]++;
    }
    for (auto x : banned) mp[x] = 0;
    int count = 0;
    string res = "";
    for (auto it : mp) {
        if (it.second > count) {
            res = it.first;
            count = it.second;
        }
    }
    return res;
}