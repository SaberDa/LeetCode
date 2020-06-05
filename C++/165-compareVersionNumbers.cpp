#include <iostream>
#include <string>

using namespace std;

int compareVersion(string version1, string version2) {
    stringstream ss1(version1);
    stringstream ss2(version2);
    string s1, s2;
    getline(ss1, s1, '.');
    getline(ss2, s2, '.');
    while (s1.size() != 0 || s2.size() != 0) {
        if (s1.size() == 0) {
            s1 = "0";
        }
        if (s2.size() == 0) {
            s2 = "0";
        }
        if (stoi(s1) > stoi(s2)) {
            return 1;
        } else if (stoi(s1) < stoi(s2)) {
            return -1;
        } else {
            s1 = "";
            s2 = "";
            getline(ss1, s1, '.');
            getline(ss2, s2, '.');
        }
    }
    return 0;
}