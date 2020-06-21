#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>

using namespace std;

int shipWithinDays(vector<int>& weights, int D) {
    int l = *max_element(weights.begin(), weights.end());
    int r = accumulate(weights.begin(), weights.end(), 0) - 1;
    while (l <= r) {
        int m = l + (r - l) / 2;
        int need = 1, cur = 0;
        for (int i = 0; i < weights.size() && need <= D; cur += weights[i++]) {
            if (cur + weights[i] > m) cur = 0, need++;
        }
        if (need > D) l = m + 1;
        else r = m - 1;
    }
    return l;
}