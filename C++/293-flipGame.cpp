#include <vector>
#include <string>

using namespace std;

vector<string> generatePossibleNextMoves(string s) {
    vector<string> res;
    if (s.empty() || s.size() < 2) return res;
    for (int i = 1; i < s.size(); i++) {
        if (s[i - 1] == '+' && s[i] == '+') {
            res.push_back(s);
            res.back()[i - 1] = '-';
            res.back()[i] = '-';
        }
    }
    return res;
}