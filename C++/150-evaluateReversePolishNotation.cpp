#include <iostream>
#include <vector>
#include <stack>
#include <string>

using namespace std;

bool isNum(string s) {
    return s != "+" && s != "-" && s != "*" && s != "/";
}

int evalRPN(vector<string>& tokens) {
    if (tokens.empty()) {
        return 0;
    }
    stack<int> s;
    for (int i = 0; i < tokens.size(); i++) {
        if (isNum(tokens[i])) {
            s.push(stoi(tokens[i]));
        } else {
            int num1 = s.top();
            s.pop();
            int num2 = s.top();
            s.pop();
            if (tokens[i] == "+") {
                s.push(num2 + num1);
            } else if (tokens[i] == "-") {
                s.push(num2 - num1);
            } else if (tokens[i] == "*") {
                s.push(num2 * num1);
            } else if (tokens[i] == "/") {
                s.push(num2 / num1);
            }
        }
    }
    return s.top();
}