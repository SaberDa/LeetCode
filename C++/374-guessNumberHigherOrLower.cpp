#include <iostream>

using namespace std;

int guess(int num);

int guessNumber(int n) {
    int l = 1, r = n;
    while (l <= r) {
        int64_t m = l + (r - l) / 2;
        if (guess(m) == 0) return m;
        else if (guess(m) == -1) r = m - 1;
        else l = m + 1;
    }
    return l;
}