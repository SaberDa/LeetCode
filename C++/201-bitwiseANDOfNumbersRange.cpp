#include <iostream>

using namespace std;

int rangeBitwiseAnd(int m , int n) {
    // Brain Kernighan's Algorithm
    while (m < n) {
        n = n & (n - 1);
    }
    return m & n;
}