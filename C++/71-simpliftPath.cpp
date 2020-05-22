#include <iostream>
#include <string>
#include <stack>

using namespace std;

string simpliftPath(string path) {
    string res;
    string s;
    stack<string> st;
    stringstream ss(path);
    while (getline(ss, s, '/')) {
        if (s == "" || s == ".") {
            continue;
        } else if (s == ".." && !st.empty()) {
            st.pop();
        } else if (s != "..") {
            st.push(s);
        }
    }
    while (!st.empty()) {
        res = "/" + st.top() + res;
        st.pop();
    }
    return res.empty() ? "/" : res;
}