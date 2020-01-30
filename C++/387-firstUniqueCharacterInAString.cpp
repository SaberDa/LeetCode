#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main() {

    string s = "leetcode";
    
    int count[26] = {0};
    for (int i = 0; i < s.length(); i++) {
        count[s[i] -'a']++;
    }
    for (int i = 0; i < s.length(); i++) {
        if (count[s[i] - 'a'] == 1) {
            cout << i << endl;
            return i;
        }
    }

    // time limit exceeded
    // int num = 0;
    // for (int i = 0; i < s.length(); i++) {
    //     num = count(s.begin(), s.end(), s[i]);
    //     if (num == 1) {
    //         cout << i << endl;
    //         return i;
    //     }
    // }


    return 0;
}