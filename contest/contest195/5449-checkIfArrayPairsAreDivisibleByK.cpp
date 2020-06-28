#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    bool canArrange(vector<int>& arr, int k) {
        if (arr.size() % 2) return false;
        unordered_map<int, int> mp;
        // Negative MOD: (num % target + target) % target
        for (auto x : arr) mp[(x % k + k) % k]++;
        for (auto it : mp) {
            int x = it.first;
            int y = (k - x) % k;
            if (mp[x] != mp[y] && x != y) return false;
            if (x == y && mp[x] % 2) return false;
        }
        return true;
    }
};