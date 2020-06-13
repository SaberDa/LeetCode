#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

int distributeCandies(vector<int>& candies) {
    if (candies.empty()) return 0;
    unordered_map<int, int> mp;
    for (auto x : candies) mp[x]++;
    return min(mp.size(), candies.size() / 2);
}