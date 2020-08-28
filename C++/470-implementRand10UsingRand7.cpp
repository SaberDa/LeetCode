#include <cmath>

using namespace std;

int randNfromK(int N, int K, const function<int()> &rand) {
    int n = log(N) / log(K);
    if (pow(K, n) < N) n++;
    int res = 0;
    do {
        res = 0;
        for (int i = 0; i < n; i++) res += (rand() - 1) * pow(K, i);
    } while (res >= N);
    return res;
}

int rand7();

int rand10() {
    return randNfromK(10, 7, []()->int{return rand7();}) + 1;
}