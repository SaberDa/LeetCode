#include <isotream>
#include <unordered_map>
#include <vector>

using namespace std;

vector<string> findRestaurant(vector<string>& list1, vector<string>& list2) {
    vector<string> res;
    unordered_map<string, int> mp;
    int min = INT_MAX;
    for (int i = 0; i < list1.size(); i++) mp[list1[i]] = i;
    for (int i = 0; i < list2.size(); i++) {
        if (mp.count(list2[i])) {
            if (mp[list2[i]] + i < min) {
                min = mp[list2[i]] + i;
                res.clear();
                res.push_back(list2[i]);
            } else if (mp[list2[i]] + i == min)
                res.push_back(list2[i]);
        }
    }
    return res;
}