class Solution {
public:
    int mctFromLeafValues(vector<int> &arr) {
        stack<int> st;
        st.push(INT_MAX);
        int res = 0;
        for (int i = 0; i < arr.size(); i++) {
            while (arr[i] > st.top()) {
                int temp = st.top();
                st.pop();
                res += temp * min(arr[i], st.top());
            }
            st.push(arr[i]);
        }
        while (st.size() >= 3) {
            int val = st.top();
            st.pop();
            res += val * st.top();
        }
        return res;
    }
};