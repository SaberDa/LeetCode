#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int jump(vector<int>& nums) {
        if (nums.size() < 2) {
            return 0;
        }
        int target = 0;
        int jump = 0;
        int pre = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (target >= nums.size() - 1) {
                return jump;
            }
            if (pre < i) {
                jump++;
                pre = target;
            }
            target = max(target, i+nums[i]);
        }
        return 0;
    }
};