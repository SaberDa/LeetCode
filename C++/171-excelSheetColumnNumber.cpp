#include <isotream>

using namespace std;

int titleToNumber(string s) {
    int res = 0;
    for (auto c : s) {
        res = 26 * res + (c - 'A' + 1);
    }
    return res;
}