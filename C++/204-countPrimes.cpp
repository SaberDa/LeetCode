#include <iostream>
#include <vector>

using namespace std;

int countPrimes(int n) {
    if (n <= 1) {
        return 0;
    }
    vector<int> res(n, true);
    res[0] = false;
    res[1] = false;
    for (int i = 0; i < sqrt(n); i++) {
        if (res[i]) {
            for (int j = i * i; j < n; j += i) {
                res[j] = false;
            }
        }
    }
    return count(res.begin(), res.end(), true);
}