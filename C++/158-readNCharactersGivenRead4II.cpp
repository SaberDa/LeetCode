#include <iostream>
#include <string>

using namespace std;

int read4(char *buf);

int i4 = 0;
int n4 = 0;
char buf4[4];

int read(char *buf, int n) {
    int i = 0;
    while (i < n) {
        if (i4 >= n4) {
            i4 = 0;
            n4 = read4(buf4);
            if (n4 == 0) {
                break;
            }
        }
        buf[i] = buf4[i4];
        i++;
        i4++;
    }
    return i;
}