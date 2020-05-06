#include <iostream>
#include <climits>
#include <cmath>

using namespace std;

int divide(int dividend, int divisor) {
    int boost = 0;
    if (dividend == INT_MIN) {
        if (divisor == -1) {
            return INT_MAX;
        } else if (divisor == 1) {
            return INT_MIN;
        } else {
            dividend++;
            boost = 1;
        }
    }
    if (divisor == INT_MIN) {
        if (dividend == INT_MAX) {
            return 0;
        } else {
            divisor++;
        }
    }

    if (dividend < 0 && dividend > divisor) {
        return 0;
    }
    if (dividend > 0 && dividend < divisor) {
        return 0;
    }

    // you should use unsigned int
    unsigned int absDividend = abs(dividend);
    unsigned int absDivisor = abs(divisor);
    int quotient = 0;

    while (static_cast<int>(absDividend) >= static_cast<int>(absDivisor)) {
        int bit = 0;
        while (bit <= 29 && (absDividend + boost >= (absDivisor << (bit + 1)))) {
            bit++;
        }

        quotient += (1 << bit);
        absDividend -= (absDivisor << bit);
    }

    if ((dividend > 0) == (divisor > 0)) {
        return quotient;
    } else {
        return quotient * -1;
    }
}

int main() {
    cout << divide(-1, -1) << endl;
    return 0;
}

