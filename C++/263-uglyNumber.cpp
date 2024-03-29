#include <iostream>
#include <vector>

using namespace std;

bool isUgly(int num) {
    if (num <= 0) return false;
    if (num < 7) return true;
    if ((num % 2) && (num % 3) && (num % 5)) return false;
    while (num % 2 == 0) num /= 2;
    while (num % 3 == 0) num /= 3;
    while (num % 5 == 0) num /= 5;
    return isUgly(num);
}