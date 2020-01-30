#include <iostream>
#include <vector>

using namespace std;

int main() {

    vector<int> nums;
    nums.push_back(3);
    nums.push_back(2);
    nums.push_back(2);
    nums.push_back(2);
    nums.push_back(5);

    if (nums.size() <= 1) {
        return nums.size();
    }

    // solution 1
    // int flag = 0;
    // int res = 1;
    // for (int i = 1; i < nums.size(); i++) {
    //     if (nums[i] > nums[i-1] && flag <= 0) {
    //         res++;
    //         flag = 1;
    //     } 
    //     if (nums[i] < nums[i-1] && flag >= 0) {
    //         res++;
    //         flag = -1;
    //     }
    // }

    // solution 2
    int res = 1;
    int i = 1;
    while (i < nums.size() && nums[i] == nums[i-1]) {
        i++;
    }
    if (i >= nums.size()) {
        return res;
    }
    bool flag = nums[i] > nums[i-1];
    while (i < nums.size()) {
        if (flag) {
            while (i+1 < nums.size() && nums[i+1] >= nums[i]) {
                i++;
            }
        } else {
            while (i+1 < nums.size() && nums[i+1] <= nums[i]) {
                i++;
            }
        }
        flag = flag ? false : true;
        res++;
        i++;
    }


    cout << res << endl;

    return 0;
}