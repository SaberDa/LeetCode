#include <string>
#include <unordered_set>

using namespace std;

int distance(string cur, string next) {
    int a = stoi(cur.substr(0, 2)) * 60 + stoi(cur.substr(2));
    int b = stoi(next.substr(0, 2)) * 60 + stoi(next.substr(2));
    return a < b ? b - a : b - a + 24 * 60;
}

void DFS(unordered_set<char> &set, string &cur, int pos, int &minDis, string &res, string &next) {
    if (pos == 2 && stoi(next.substr(0, 2)) >= 24) return;
    if (pos == 4) {
        if (stoi(next.substr(2)) >= 60) return;
        int dis = distance(cur, next);
        if (dis < minDis) {
            minDis = dis;
            res = next;
        }
        return;
    }
    for (auto c : set) {
        next.push_back(c);
        DFS(set, cur, pos + 1, minDis, res, next);
        next.pop_back();
    }
}

string nextClosestTime(string time) {
    string cur = time.substr(0, 2) + time.substr(3);
    unordered_set<char> set;
    for (auto c : cur) set.insert(c);
    if (set.size() == 1) return time;
    int minDis = 24 * 60;
    string res = "", next = "";
    DFS(set, cur, 0, minDis, res, next);
    res.insert(res.begin() + 2, ':');
    return res;
}