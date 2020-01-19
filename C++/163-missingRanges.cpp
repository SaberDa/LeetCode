#include <iostream>
#include <vector>
#include <string>

using namespace std;

string combine(int a, int b);

int main() {

    vector<int> nums;
    nums.push_back(0);
    nums.push_back(1);
    nums.push_back(3);
    nums.push_back(50);
    nums.push_back(75);
    int lower = 0;
    int upper = 99;

    vector<string> res;
    if (nums.empty()) {
        res.push_back(combine(lower, upper));
        return 0;
    }

    int cur = lower;
    // if (nums[0] > lower) {
    //     if (nums[0]-1 == lower) {
    //         res.push_back(combine(lower, lower));
    //     } else {
    //         res.push_back(combine(lower, nums[0]-1));
    //     }
    // }
    for (int i = 0; i < nums.size(); i++) {
        if (i > 0 && nums[i] == nums[i-1]) {
            continue;
        }
        string s = "";
        if (nums[i] > cur) {
            s += to_string(cur);
            cur++;
        }
        if (nums[i] > cur) {
            s += "->" + to_string(nums[i]-1);
        }
        if (cur < 2147483647 && nums[i] < 2147483647) {
            cur = nums[i] + 1;
        }
        if (!s.empty()) {
            res.push_back(s);
        }
    }
    if (nums.back() == upper - 1) {
        res.push_back(to_string(upper));
    } else if (nums.back() < upper) {
        string s = to_string(nums.back()+1) + "->" + to_string(upper);
        res.push_back(s);
    }

    for (int i = 0; i < nums.size(); i++) {
        cout << res[i] << endl;
    }


    return 0;
}

string combine(int a, int b) {
    string str = "";
    if (a == b) {
        str = to_string(a);
    } else {
        str = to_string(a) + "->" + to_string(b);
    }
    return str;
}