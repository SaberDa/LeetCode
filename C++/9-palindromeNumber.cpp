#include <iostream>
#include <string>

using namespace std;

bool isPalindrome(int x) {
    string temp = to_string(x);
    for (int i = 0, j = temp.size() - 1; i < j; i++, j--) {
        if (temp[i] != temp[j]) {
            return false;
        }
    }
    return true;
}