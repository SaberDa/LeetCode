#include <vector>

using namespace std;

bool isValid(string S) {
    vector<char> st;
    for (auto c : S) {
        if (c == 'a' || c == 'b') 
            st.push_back(c);
        else {
            int n = st.size();
            if (n < 2 || st[n - 1] != 'b' || st[n - 2] != 'a')
                return false;
            st.pop_back();
            st.pop_back();
        } 
    }
    return st.empty();
}