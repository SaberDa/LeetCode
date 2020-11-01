#include <string>

using namespace std;

int repeatedStringMatch(string a, string b) {
    if (b.empty()) return 1;
    for (int i = 0, j = 0; i < a.size() && j < b.size(); i++, j = 0) {
        while (i < a.size() && a[i] != b[j]) i++;
        int k = i, count = 1;
        while (a[k++] == b[j++]) {
            if (j == b.size()) return count;
            if (k == a.size()) {
                k = 0;
                count++;
            }
        }
    }
    return -1;
}