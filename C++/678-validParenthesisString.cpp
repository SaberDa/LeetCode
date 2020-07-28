#include <iostream>
#include <stack>

using namespace std;

bool checkValidString(string s) {
    if (s.empty()) return true;
    int left = 0, right = 0;
    for (auto c : s) {
        if (c == '(') right++, left++;
        else if (c == '*') right++, left = max(left - 1, 0);
        else right--, left = max(left - 1, 0);
        if (right < 0) return false;
    }
    return left == 0;
}

// bool checkValidString(string s) {
//     if (s.empty()) return true;
//     stack<int> st, star;
//     for (int i = 0; i < s.size(); i++) {
//         if (s[i] == ')') {
//             if (!st.empty()) st.pop();
//             else if (!star.empty()) star.pop();
//             else return false;
//         } else if (s[i] == '(') st.push(i);
//         else star.push(i);
//     }
//     while (!st.empty() && !star.empty()) {
//         if (st.top() > star.top()) return false;
//         st.pop(), star.pop();
//     }
//     return st.empty();
// }