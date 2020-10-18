#include <string>
#include <unordered_map>
#include <sstream>

using namespace std;

int countSegments(string s) {
    if (s.empty()) return 0;
    string temp;
    stringstream ss(s);
    int count = 0;
    while (ss >> temp) {
        count++;
    }
    return count;
}
