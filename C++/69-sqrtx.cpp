#include <isotream>
#include <cmath>

using namespace std;

// use bit
int mySqrt(int x) {
    if (x < 2) {
        return x;
    }
    long int r = mySqrt(x >> 2) << 1;
    long int left = r;
    long int right = r + 1;
    return (right * right > x) ? left : right; 
}

// Newton's solution
int mySqrt2(int x) {
    long int r = x;
    while (pow(r, 2) > x) {
        r = (r + x / r) / 2;
    }
    return r;
}

// binary search
int mySqrt3(int x) {
    if (x < 2) {
        return x;
    }
    int low = 1;
    int high = x;
    while (true) {
        int mid = low + (high - low) / 2;
        if (mid > x/mid) {
            high = mid - 1;
        } else if (mid + 1 > x / (mid + 1)) {
            return mid;
        } else {
            low = mid + 1;
        }
    }
}