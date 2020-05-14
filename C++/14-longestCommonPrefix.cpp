#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;

string longestCommonPrefix(vector<string>& strs) {
    if (strs.empty()) {
        return "";
    }
    sort(strs.begin(), strs.end());
    string first = strs[0];
    string last = strs[strs.size() - 1];
    int i = 0;
    for (; i < min(first.size(), last.size()); i++) {
        if (first[i] != last[i]) {
            break;
        }
    }
    return first.substr(0, i);
}

int main() {
    vector<string> strs({{"flower"}, {"flow"}, {"flight"}});
    cout << longestCommonPrefix(strs) << endl;
    return 0;
}