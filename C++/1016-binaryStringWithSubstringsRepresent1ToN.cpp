#include <string>

using namespace std;

string binary(int i) {
    string res = "";
    while (i > 0) {
        res = to_string(i % 2) + res;
        i /= 2;
    }
    return res;
} 

bool queryString(string S, int N) {
    int i;
    for (i = 1; i <= N; i++) {
        string temp = binary(i);
        if (S.find(temp) == string::npos) return false;
    }
    return true;
}