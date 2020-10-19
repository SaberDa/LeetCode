#include <string>
#include <algorithm>
#include <vector>

using namespace std;

string optimalDivision(vector<int> &nums) {
    if (nums.empty()) return "";
    string res = to_string(nums[0]);
    if (nums.size() > 2) {
        res += "/(";
        for (int i = 1; i < nums.size(); i++) {
            res += to_string(nums[i]) + '/';
        }
        res.pop_back();
        res += ')';
    } else if (nums.size() == 2) {
        res += '/' + to_string(nums[1]);
    }
    return res;
}