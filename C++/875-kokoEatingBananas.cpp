#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


int minEatingSpeed(vector<int>& piles, int H) {
    int l = 1, r = *max_element(piles.begin(), piles.end());
    while (l <= r) {
        int m = l + (r - l) / 2;
        int temp = 0;
        for (auto x : piles) {
            temp += ceil(x * 1.0 / m);
        }
        if (temp > H) l = m + 1;
        else r = m - 1;
    }
    return l;
}