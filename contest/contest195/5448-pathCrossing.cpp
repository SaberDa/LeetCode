#include <set>

using namespace std;

class Solution {
public:
    
    
    bool isPathCrossing(string path) {
        // unordered_map<int, vector<int>> mp;
        // mp[0].push_back(0);
        // int x = 0, y = 0;
        // for (auto c : path) {
        //     if (c == 'N') x++;
        //     else if (c == 'S') x--;
        //     else if (c == 'W') y++;
        //     else if (c == 'E') y--;
        //     if (find(mp[x].begin(), mp[x].end(), y) != mp[x].end()) return true;
        //     mp[x].push_back(y);
        // }
        // return false;
        
        set<pair<int, int>> st;
        st.insert({0, 0});
        int x = 0, y = 0;
        for (auto c : path) {
            if (c == 'N') x++;
            else if (c == 'S') x--;
            else if (c == 'W') y++;
            else if (c == 'E') y--;
            if (st.count({x, y})) return true;
            st.insert({x, y});
        }
        return false;
    }
};