#include <iostream>

using namespace std;

int arrangeCoins(int n) {
    int l = 0, r = n;
    while (l <= r) {
        int64_t m = l + (r - l) / 2;
        int64_t temp = (m + 1) * m / 2;
        if (temp == n) return m;
        if (temp < n) l = m + 1;
        else r = m - 1;
    }
    return l - 1;
}