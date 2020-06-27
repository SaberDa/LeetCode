#include <iostream>
#include <string>
#include <stack>

using namespace std;

string decodeString(string s) {
    stack<char> st;
    for (int i = 0; i < s.size(); i++) {
        if (s[i] != ']') st.push(s[i]);
        else {
            string str = "";
            while (st.top() != '[') {
                str = st.top() + str;
                st.pop();
            }
            st.pop();
            string num = "";
            while (!st.empty() && isdigit(st.top())) {
                num = st.top() + num;
                st.pop();
            }
            int k = stoi(num);
            while (k--) {
                for (int j = 0; j < str.size(); j++)
                    st.push(str[j]);
            }
        }
    }
    s = "";
    while (!st.empty()) {
        s = st.top() + s;
        st.pop();
    }
    return s;
}