#include <iostream>
#include <vector>

using namespace std;

int fixedPoint(vector<int>& A) {
    int l = 0, r = A.size() - 1;
    while (l <= r) {
        int m = l + (r - l) / 2;
        if (A[m] == m) {
            if (l == r) return l;
            r = m;
        } else if (A[m] > m) r = m - 1;
        else l = m + 1;
    }
    return -1;
}