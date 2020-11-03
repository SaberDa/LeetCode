#include <vector>
#include <string>

using namespace std;

int scoreOfParentheses(string S) {
    int res = 0, depth = 0;
    char pre;
    for (auto cur : S) {
        cur == '(' ? depth++ : depth--;
        if (pre == '(' && cur == ')') {
            res += 1 << depth;
        }
        pre = cur;
    }
    return res;
}