#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <functional>

using namespace std;

// use native strstr
int strStr(string haystack, string needle) {
    const char* a = haystack.c_str();
    const char* b = needle.c_str();
    const char* c = strstr(a, b);
    if (c == NULL) {
        return -1;
    }
    return c - a;
}

// use BF
// time exceed
int strStrBF(string haystack, string needle) {
        if (needle.empty()) {
            return 0;
        }
        if (haystack.size() < needle.size()) {
            return -1;
        }
        for (int i = 0; i < haystack.size(); i++) {
            if (haystack[i] == needle[0] && isEqual(haystack.substr(i), needle)) {
                return i;
            }
        }
        return -1;
}

bool isEqual(string str, string needle) {
    if (str.size() < needle.size()) {
        return false;
    }
    for (int i = 0; i < needle.size(); i++) {
        if (str[i] != needle[i]) {
            return false;
        }
    }
    return true;
}

// use find
int strStrFind(string haystack, string needle) {
    return haystack.find(needle);
}

// use STL
int strStrSTL(string haystack, string needle) {
    if (needle.empty()) {
        return 0;
    }
    if (haystack.empty()) {
        return -1;
    }
    if (needle.length() > haystack.length()) {
        return -1;
    }
    auto it = search(haystack.begin(), haystack.end(), boyer_moore_horspool_searcher(needle.begin(), needle.end()));
    if (it != haystack.end()) {
        return it - haystack.begin();
    } else {
        return -1;
    }
}


int strStr(string haystack, string needle) {
        int m = haystack.size();
        int n = needle.size();
        if (n == 0) {
            return 0;
        }
        vector<int> dp(n, 0);
        int j = 0;
        for (int i = 1; i < n; i++) {
            while (j > 0 && needle[j] != needle[i]) {
                j = dp[j-1];
            }
            if (needle[j] == needle[i]) {
                j++;
            }
            dp[i] = j;
        }
        j = 0;
        for (int i = 0; i < m; i++) {
            while (j > 0 && needle[j] != haystack[i]) {
                j = dp[j-1];
            }
            if (needle[j] == haystack[i]) {
                j++;
            }
            if (j == n) {
                return i - j + 1;
            }
        }
        return -1;
}

int main() {
    cout << strStr("aaaaa", "bba") << endl;
    return 0;

}