#include <iostream>
#include <string>

using namespace std;

string reverseWords(string s) {
    // TLE
    // string res = "";
    // if (s.empty()) return res;
    // for (int i = 0; i < s.size(); i++) {
    //     while (i < s.size() && s[i] == ' ') i++;
    //     int j = i;
    //     while (i < s.size() && s[i] != ' ') i++;
    //     string temp = s.substr(j, i - j);
    //     reverse(temp.begin(), temp.end());
    //     res = res + temp + " ";
    // }
    // res.pop_back();
    // return res;
    int j = 0;
    for (int i = 0; i < s.size(); i++) {
        if (s[i] == ' ') {
            reverse(s.begin() + j, s.begin() + i);
            j = i + 1;
        }
    }
    reverse(s.begin() + j, s.end());
    return s;
}