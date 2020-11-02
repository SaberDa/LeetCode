#include <string>
#include <vector>
#include <algorithm>

using namespace std;

string maskPII(string S) {
    string res = "", nums = "";
    auto pos = S.find('@');
    if (pos == string::npos) {
        for (auto c : S) {
            if (isdigit(c)) nums.push_back(c);
        }
        int n = nums.size();
        res = n == 13 ? "+***-" : n == 12 ? "+**-" : n == 11 ? "+*-" : "";
        res.append("***-***-" + nums.substr(n - 4));
    } else {
        res = S.substr(0, 1) + "*****" + S.substr(pos - 1);
        transform(res.begin(), res.end(), res.begin(), ::tolower);
    }
    return res;
}