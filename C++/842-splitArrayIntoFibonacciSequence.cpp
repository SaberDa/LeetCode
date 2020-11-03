#include <vector>
#include <string>

using namespace std;

bool helper(string S, vector<int> &res, int pos) {
    if (pos == S.size()) return res.size() >= 3;
    int len = S[pos] == '0' ? 1 : 10;
    for (int i = 0; i < len && pos + i < S.size(); i++) {
        long long cur = stoll(S.substr(pos, i + 1));
        if (cur > INT_MAX) return false;
        int size = res.size();
        if (size < 2 || (size > 1 && res[size - 2] == cur - res[size - 1])) {
            res.push_back((int)cur);
            if (helper(S, res, pos + i + 1)) return true;
            res.pop_back();
        }
    }
    return false;
}

vector<int> splitIntoFibonacci(string S) {
    vector<int> res;
    return helper(S, res, 0) ? res : vector<int>();
}