#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

bool judgeCircle(string moves) {
    int v = 0, h = 0;
    unordered_map<char, int> mp{{'R', 1}, {'L', -1}, {'U', -1}, {'D', 1}};
    for (auto x : moves) {
        if (x == 'L' || x == 'R') h += mp[x];
        else v += mp[x];
    }
    return v == 0 && h == 0;
}