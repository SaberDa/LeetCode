#include <vector>
#include <string>
#include <stack>

using namespace std;

int nextGreaterElement(int n) {
    string res = to_string(n);
    stack<int> st;
    int idx = -1;
    for (int i = res.size() - 1; i >= 0; i--) {
        while (!st.empty() && res[i] < res[st.top()]) {
            idx = st.top();
            st.pop();
        }
        if (idx != -1) {
            swap(res[idx], res[i]);
            sort(res.begin() + i + 1, res.end());
            break;
        } 
        st.push(i);
    }
    if (idx == -1) return -1;
    if (stoll(res) > INT_MAX) return -1;
    return stoi(res);
}