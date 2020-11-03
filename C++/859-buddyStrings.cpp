#include <string>
#include <unordered_set>

using namespace std;

bool buddyStrings(string A, string B) {
    if (A.size() != B.size()) return false;
    if (A == B) {
        unordered_set<char> set;
        for (auto c : A) {
            if (set.count(c)) return true;
            else set.insert(c);
        }
        return false;
    }
    bool swapped = false;
    int pos = -1;
    for (int i = 0; i < A.size(); i++) {
        if (A[i] != B[i]) {
            if (pos == -1) pos = i;
            else if (swapped || A[pos] != B[i] || A[i] != B[pos]) return false;
            else swapped = true;
        }
    }
    return swapped;
}