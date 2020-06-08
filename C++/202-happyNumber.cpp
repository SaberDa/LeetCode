#include <iostream>
#include <unordered_set>
#include <cmath>

using namespace std;

int calc(int x) {
    int sum = 0;
    while (x > 0) {
        sum += pow(x % 10, 2);
        x /= 10;
    }
    return x;
}

bool isHappy(int n) {
    unordered_set<int> res;
    while (n != 1 && res.count(n) == 0) {
        res.insert(n);
        n = calc(n);
    }
    return n == 1;
}