#include <iostream>
#include <vector>

using namespace std;

class CombinationIterator {
private:
    vector<string> cnt;
    string s;
    int len;
    string path = "";
public:

    void DFS(string s, int len, string path, int index) {
        if (index > s.size()) return;
        if (path.size() == len) {
            cnt.push_back(path);
            return;
        }
        for (int i = index; i < s.size(); i++) {
            path.push_back(s[i]);
            DFS(s, len, path, i + 1);
            path.pop_back();
        }
    }

    CombinationIterator(string characters, int combinationLength) {
        s = characters;
        len = combinationLength;
        DFS(s, len, path, 0);
        sort( cnt.rbegin(), cnt.rend());
    }

    string next() {
        if (cnt.empty()) return "";
        string res = cnt.back();
        cnt.pop_back();
        return res;
    }

    bool hasNext() {
        return !cnt.empty();
    }

};