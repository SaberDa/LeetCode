#include <iostream>
#include <string>
#include <stack>

using namespace std;

bool isValid(string s) {
    stack<char> temp;
    if (s.empty()) {
        return true;
    }
    for (int i = 0; i < s.size(); i++) {
        if (s[i] == '(' || s[i] == '[' || s[i] == '{') {
            temp.push(s[i]);
        } else if (s[i] == ')' && !temp.empty()) {
            char c = temp.top();
            if (c == '(') {
                temp.pop();
                
            } else {
                return false;
            }
        } else if (s[i] == ']' && !temp.empty()) {
            char c = temp.top();
            if (c == '[') {
                temp.pop();
            } else {
                return false;
            }
        } else if (s[i] == '}' && !temp.empty()) {
            char c = temp.top();
            if (c == '{') {
                temp.pop();
            } else {
                return false;
            }
        } else {
            return false;
        }
    }
    return (temp.empty()) ? true : false;
}

int main() {
    cout << isValid("{[]}") << endl;
    return 0;
}