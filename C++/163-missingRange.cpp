#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

string combina(int left, int right);

int main() {
    vector<int> nums;
    nums.push_back(0);
    nums.push_back(1);
    nums.push_back(3);
    nums.push_back(50);
    nums.push_back(75);
    int lower = 0;
    int upper = 99;

    // vector<string> res;

    // int start = 0;
    // int last = start;
    // int count = 0;
    // for (; start <= upper && count < nums.size(); start = last, last++) {
    //     while(last <= upper && last != nums[count]) {
    //         last++;
    //     }
    //     if (start == nums[count]) {
    //         start++;
    //         count++;
    //     } else {
    //         res.push_back(combina(start, last));
    //     }
    // }

    for (int i = 0; i < nums.size(); i++) {
        cout << nums[i] << endl;
    }

    return 0;
}

string combina(int left, int right) {
    string str;
    if (left == right) {
        str = to_string(left);
    } else {
        str = to_string(left) + "->" + to_string(right);
    }
    return str;
}