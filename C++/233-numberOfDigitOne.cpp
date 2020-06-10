#include <iostream>
#include <unordered_map>

using namespace std;

int countDigitOne(int n) {
    int res = 0;
    if (n <= 0) return 0;
    if (n <= 9) return 1;
    unordered_map<int, int> mp;
    mp[9] = 1;
    for (int i = 9; i <= (INT_MAX - 9) / 10; i = i * 10 + 9) {
        mp[i * 10 + 9] = mp[i] * 10 + (i + 1);
    }

    int temp = n, divisor = 1;
    while (temp / 10) {
        temp /= 10;
        divisor *= 10;
    }
    res += (n / divisor) * mp[divisor - 1];
    res += (n / divisor > 1) ? divisor : 0;
    res += (n / divisor == 1) ? n % divisor + 1 : 0;
    res += countDigitOne(n % divisor);
    return res;
}