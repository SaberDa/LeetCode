#include <iostream>
#include <vector>
#include <string>

using namespace std;

void helper(vector<int>& res, int a, int b, char cur) {
    if (cur == '+') res.push_back(a + b);
    else if (cur == '-') res.push_back(a - b);
    else res.push_back(a * b);
    return;
}

vector<int> diffWaysToCompute(string input) {
    vector<int> res;
    if (input.empty()) return res;
    for (int i = 0; i < input.size(); i++) {
        char cur = input[i];
        if (cur == '+' || cur == '-' || cur == '*') {
            vector<int> res1 = diffWaysToCompute(input.substr(0, i));
            vector<int> res2 = diffWaysToCompute(input.substr(i + 1));
            for (auto n1 : res1)
                for (auto n2 : res2)
                    helper(res, n1, n2, cur);
        }
    }
    if (res.empty()) {
        res.push_back(stoi(input.c_str()));
    }
    return res;
}