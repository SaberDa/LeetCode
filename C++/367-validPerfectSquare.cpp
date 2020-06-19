#include <iostream>

using namespace std;

bool isPerfectSquare(int num) {
    if (num == 1) return true;
    int l = 1, r = num / 2;
    while (l <= r) {
        int64_t m = l + (r - l) / 2;
        int64_t temp = m * m;
        if (temp == num) return true;
        (temp > num) ? r = m - 1 : l = m + 1;
    }
    return false;
}