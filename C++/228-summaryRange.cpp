#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

int main() {
    vector<int> nums;
    nums.push_back(0);
    // nums.push_back(1);
    // nums.push_back(2);
    // nums.push_back(4);
    // nums.push_back(5);
    // nums.push_back(7);
    nums.push_back(2);
    nums.push_back(3);
    nums.push_back(4);
    nums.push_back(6);
    nums.push_back(8);
    nums.push_back(9);

    vector<int> res;

    int first = 0;
    int last = first + 1;
    int temp = first;

    while (last <= nums.size()) {
        if (nums[temp]+1 != nums[last]) {
            // int k = nums[temp];
            res.push_back(nums[temp]);
            res.push_back(nums[temp+1]);
            temp++;
            last++;
        } else {
            temp = last;
            last++;
        }

    }

    for (int i = 0; i < res.size(); i++) {
        cout << res[i] << endl;
    }

    return 0;

}