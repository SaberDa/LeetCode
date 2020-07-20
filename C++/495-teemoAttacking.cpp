#include <iostream>
#include <vector>

using namespace std;

int findPoisonedDuration(vector<int>& timeSeries, int duration) {
    int res = 0, pos = -1;
    for (auto x : timeSeries) {
        if (pos > x) res -= pos - x;
        res += duration;
        pos = x + duration;
    }
    return res;
}