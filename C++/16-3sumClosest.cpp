#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

int main() {

    vector<int> nums;
    nums.push_back(0);
    nums.push_back(2);
    nums.push_back(1);
    nums.push_back(-3);
    int target = 1;


    // two pointers
    // first sort the input vector
    // fix one element
    // then make the next element as the left pointer
    // make the last element as the right pointer
    // compare the abs with these three elements sum with the targer
    // reflesh the res which the min

    vector<int> result;
    int final = 0;
    if (nums.empty()) {
        cout << target << endl;
        return target;
    }
    if (nums.size() <= 3) {
        for (int i = 0; i < nums.size(); i++) {
            final += nums[i];
        }
        cout << final << endl;
        return final;
    }

    sort(nums.begin(), nums.end());

    int flag = target;
    int init = nums[0] + nums[1] + nums[2];
    for (int i = 0; i <= nums.size()-3; i++) {
        // while (i > 0 && i <= nums.size()-3 && nums[i] == nums[i-1]) {
        //     i++;
        // }
        int m = i+1;
        int r = nums.size() - 1;
        
        while (m < r) {
            int res = nums[m] + nums[r] + nums[i];
            if (abs(res - target) < abs(init - target)) {
                init = res;
            }
            if (res > target) {
                r--;
            } else if (res == target) {
                break;
            } else {
                m++;
            }   
        }   
    }
    cout << init << endl;




    return 0;
}