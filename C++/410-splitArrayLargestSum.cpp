class Solution {
public:

    bool helper(vector<int> &nums, int m, long long sum) {
        int count = 1;
        long long s = 0;
        for (auto &x : nums) {
            s += x;
            if (s > sum) {
                s = x;
                count++;
            }
        }
        return count <= m;
    }

    int splitArray(vector<int> &nums, int m) {
        if (nums.empty()) return 0;
        long long left = 0, right = 0;
        for (auto &x : nums) {
            left = max(left, (long long)x);
            right += x;
        }
        while (left <= right) {
            long long mid = left + (right - left) / 2;
            if (helper(nums, m, mid)) right = mid - 1;
            else left = mid + 1;
        }
        return left;
    }
};