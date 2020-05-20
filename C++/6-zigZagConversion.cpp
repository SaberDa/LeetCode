#include <iostream>
#include <vector>
using namespace std;

string convert(string s, int numRows) {
    if (numRows <= 1) {
        return s;
    }
    int d = 1;
    string res;
    int row = 0;
    vector<string> temp(numRows, "");
    for (auto c : s) {
        temp[row].push_back(c);
        row += d;
        if (row == numRows - 1) {
            d = -1;
        }
        if (row == 0) {
            d = 1;
        }
    }
    for (auto it : temp) {
        res.append(it);
    }
    return res;
}