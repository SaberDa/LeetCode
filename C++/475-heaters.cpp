#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int findRadius(vector<int>& houses, vector<int>& heaters) {
    sort(houses.begin(), houses.end());
    sort(heaters.begin(), heaters.end());
    vector<int> res(houses.size(), INT_MAX);
    for (int i = 0, j = 0; i < houses.size() && j < heaters.size();) {
        if (houses[i] <= heaters[j]) {
            res[i] = heaters[j] - houses[i];
            i++;
        } else j++;
    }
    for (int i = houses.size() - 1, j = heaters.size() - 1; i >= 0 && j >= 0;) {
        if (houses[i] >= heaters[j]) {
            res[i] = min(res[i], houses[i] - heaters[j]);
            i--;
        } else j--;
    }
    return *max_element(res.begin(), res.end());
}