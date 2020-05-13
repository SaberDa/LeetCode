#include <iostream>
#include <string>

int read4(char *buf);

int read(char *buf, int n) {
    if (n <= 0) {
        return n;
    }
    int bytes = 0;
    int sum = 0;
    while (true) {
        bytes = read4(buf + sum);
        sum += bytes;
        if (bytes == 0) {
            return sum;
        }
        if (sum >= n) {
            return n;
        }
    }
}