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

    vector<string> res;
    int i = 0;
    int j = i+1;
    for (; i < nums.size(); i = j, j = i+1) {
        while (j < nums.size() && nums[j] == nums[j-1]+1) j++;
        if (i == j-1) {
            res.push_back(to_string(nums[i]));
        } else { 
            res.push_back(to_string(nums[i]) + "->" + to_string(nums[j-1]));
        }
    }


    for (int i = 0; i < res.size(); i++) {
        cout << res[i] << endl;
    }

    return 0;

}