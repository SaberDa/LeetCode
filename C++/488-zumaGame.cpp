#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
    unordered_map<char, int> mp;
    string res;
    int mins = INT_MAX;
public:

    void helper(int used) {
        if (res.empty()) {
            mins = min(mins, used);
            return;
        }
        for (int i = 0; i < res.size();) {
            int j = i;
            char temp = res[i];
            while (j < res.size() && res[j] == temp) j++;
            if ((j - i) < 3) {
                int rem = 3 - (j - i);
                if (mp[temp] >= rem) {
                    res.erase(res.begin() + i, res.begin() + j);
                    mp[temp] -= rem;
                    helper(used + rem);
                    mp[temp] += rem;
                    res.insert(i, j - i, temp);
                }
            } else {
                res.erase(res.begin() + i, res.begin() + j);
                helper(used);
                res.insert(i, j - i, temp);
            }
            i = j;
        }
    }

    int findMinStep(string board, string hand) {
        for (auto c : hand) mp[c]++;
        res = board;
        helper(0);
        return mins == INT_MAX ? -1 : mins;
    }

};