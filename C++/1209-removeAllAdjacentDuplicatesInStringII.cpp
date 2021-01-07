#include <string>
#include <stack>
#include <vector>

using namespace std;

string removeDuplicates(string s, int k) {
    vector<pair<char, int>> st;
    string res = "";
    for (auto c : s) {
        if (st.empty() || st.back().first != c) st.push_back({c, 0});
        if (++st.back().second == k) st.pop_back();
    }
    for (auto it : st) {
        res += string(it.second, it.first);
    }
    return res;
}