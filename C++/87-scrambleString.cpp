#include <iostream>
#include <string>
#include <vector>

using namespace std;

bool isScramble(string s1, string s2) {
    if (s1 == s2) {
        return true;
    }
    int head = 0;
    int n = s1.size();
    vector<int> s1Z(128, 0), s2F(128, 0), s2B(128, 0);
    int any = 0;
    while (head < n - 1) {
        s1Z[s1[head]]++;
        s2F[s2[head]]++;
        head++;
        s2B[s2[n - head]]++;
        if (s1Z == s2F) {
            any |= isScramble(s1.substr(0, head), s2.substr(0, head)) & isScramble(s1.substr(head), s2.substr(head));
        } else if (s1Z == s2B) {
            any |= isScramble(s1.substr(0, head), s2.substr(n - head)) & isScramble(s1.substr(head), s2.substr(0, n - head));
        }
        if (any) {
            return true;
        }
    }
    return any;
}
