#include <vector>
#include <string>
#include <set>

using namespace std;

int numSpecialEquivGroups(vector<string>& A) {
    set<pair<string, string>> st;
    for (auto s : A) {
        pair<string, string> p;
        for (int i = 0; i < s.size(); i++) {
            if (i % 2 == 0) p.first += s[i];
            else p.second += s[i];
        }
        sort(p.first.begin(), p.first.end());
        sort(p.second.begin(), p.second.end());
        st.insert(p);
    }
    return st.size();
}