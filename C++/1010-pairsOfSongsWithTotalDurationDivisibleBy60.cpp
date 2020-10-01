#include <vector>
#include <unordered_map>

using namespace std;

int numPairsDivisibleBy60(vector<int> &time) {
    if (time.empty()) return 0;
    int res = 0;
    vector<int> temp(60);
    for (auto t : time) {
        res += temp[(60 - t % 60) % 60];
        temp[t % 60]++;
    }
    return res;
}