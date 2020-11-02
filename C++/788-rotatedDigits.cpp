#include <set>
#include <string>

using namespace std;

int rotatedDigits(int N) {
    int res = 0;
    for (int i = 1; i <= N; i++) {
        string temp = to_string(i);
        set<char> st(temp.begin(), temp.end());
        if (st.count('3') || st.count('4') || st.count('7')) continue;
        if (st.count('2') || st.count('5') || st.count('6') || st.count('9')) res++;
    }
    return res;
}