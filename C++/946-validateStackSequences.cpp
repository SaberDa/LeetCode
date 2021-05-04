class Solution {
public:
    bool validateStackSequences(vector<int> &pushed, vector<int> &popped) {
        stack<int> st;
        for (int i = 0; i < pushed.size(); i++) {
            st.push(pushed[i]);
            while (!st.empty() && st.top() == popped.front()) {
                st.pop();
                popped.erase(popped.begin());
            }
        }
        return st.empty();
    }
};