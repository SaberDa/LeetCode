#include <iostream>
#include <vector>
#include <string>


using namespace std;

string largestNumber(vector<int>& nums) {
    if (nums.empty()) {
        return "";
    }
    vector<string> temp;
    for (auto it : nums) {
        temp.push_back(to_string(it));
    }
    sort(temp.begin(), temp.end(), [](const string& m, const string& n) {return m+n > n+m;});
    if (temp[0] == "0") {
        return "0";
    }
    string res;
    for (auto it : temp) {
        res += it;
    }
    return res;
}