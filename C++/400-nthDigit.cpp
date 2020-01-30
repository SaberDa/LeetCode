#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main() {

    int n;

    n = 3;

    long length = 9;
    int digit = 1;
    while (n - length*digit > 0) {
        n = n - length * digit;
        length *= 10;
        digit++;
    }
    long num = 1;
    for (int i = 1; i < digit; i++) {
        num *= 10;
    }
    int index = n % digit;
    if (n % digit == 0) {
        index = digit;
    }
    if (index == digit) {
        num = num + n/digit - 1;
    } else {
        num = num + n/digit;
    }
    for (int i = index; i < digit; i++) {
        num /= 10;
    }
    int ans = num % 10;

    cout << ans <<endl;

    return 0;
}