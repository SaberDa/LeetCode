#include <iostream>

using namespace std;

int addDigits(int num) {
    if (num < 10) return num;
    int temp = 0;
    while (num) {
        temp += num % 10;
        num /= 10;
    }
    return addDigits(temp);
}