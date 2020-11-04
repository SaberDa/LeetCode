#include <string>

using namespace std;

string reverseOnlyLetters(string S) {
    int i = 0, j = S.size() - 1;
    while (i < j) {
        if (isalpha(S[i]) && isalpha(S[j])) {
            swap(S[i++], S[j--]);
        } else if (isalpha(S[i]) && !isalpha(S[j])) {
            j--;
        } else i++;
    }
    return S;
}