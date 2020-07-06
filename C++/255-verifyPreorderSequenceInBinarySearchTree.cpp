#include <vector>
#include <stack>

using namespace std;

bool verifyPreorder(vector<int>& preorder) {
    stack<int> st;
    int pre = INT_MIN;
    for (int i = 0; i < preorder.size(); i++) {
        while (!st.empty() && preorder[i] > pre) {
            pre = st.top();
            st.pop();
        }
        if (preorder[i] < pre) return false;
        st.push(preorder[i]);
    }
    return true;
}