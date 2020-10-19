#include <string>
#include <algorithm>

using namespace std;

bool checkRecord(string s) {
    if (count(s.begin(), s.end(), 'A') > 1 || s.find("LLL") != string::npos) return false;
    return true;
}