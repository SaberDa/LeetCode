#include <iostream>

bool isBadVersion(int version);

int firstBadVersion(int n) {
    if (n == 0) return 0;
    int l = 1, r = n;
    while (l <= r) {
        int m = l + (r - l) / 2;
        if (isBadVersion(m)) r = m - 1;
        else l = m + 1;
    }
    return l;
}