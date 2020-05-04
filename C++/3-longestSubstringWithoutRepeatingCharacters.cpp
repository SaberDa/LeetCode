#include <iostream>
#include <string>
#include <unordered_map>
#include <algorithm>

using namespace std;

int main() {
    string s;

    s = "abcabcbb";
    
    if (s.empty()) {
        return 0;
    }

    int maxLength = 0;
    int start = 0;

    unordered_map<char, int> substr;
    for (int end = 0; end < s.size(); end++) {
        char cur = s.at(end);
        substr[cur]++;

        while (substr[cur] != 1) {
            char left = s.at(start);
            substr[left]--;
            if (substr[left] == 0) {
                substr.erase(left);
            }
            start++;
        }
        maxLength = max(maxLength, end - start + 1);
    }

    cout << maxLength << endl;

    return maxLength;
}