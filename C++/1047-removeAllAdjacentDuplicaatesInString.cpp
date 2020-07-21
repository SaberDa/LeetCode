#include <iostream>
#include <stack>
#include <string>

using namespace std;

string removeDuplicates(string S) {
    stack<char> st;
    string res = "";
    for (auto c : S) {
        if (!st.empty()) {
            if (st.top() == c) st.pop();
            else st.push(c);
        } else {
            st.push(c);
        }
    }
    while (!st.empty()) {
        res.push_back(st.top());
        st.pop();
    }
    reverse(res.begin(), res.end());
    return res;
}