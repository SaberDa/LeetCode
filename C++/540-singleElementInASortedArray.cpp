class Solution {
public:
    int singleNonDuplicate(vector<int> &nums) {
        if (nums.size() == 1) return nums[0];
        int l = 0, r = nums.size() - 1;
        int m = l + (r - l) / 2;
        while (l < r - 2) {
            if (nums[m] == nums[m + 1]) m++;
            if ((r - m) % 2) l = m + 1;
            else r = m;
            m = l + (r - l) / 2;
        }
        return nums[l] == nums[l + 1] ? nums[r] : nums[l];
    }
};