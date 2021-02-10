class Solution {
public:

    int helper(MountainArray &mountainArr, int target, int l, int r, bool asc) {
        while (l <= r) {
            int m = l + (r - l) / 2;
            int val = mountainArr.get(m);
            if (val == target) return m; 
            else if (asc == val < target) l = m + 1;
            else r = m - 1;
        }
        return -1;
    }

    int findInMountainArray(int target, MountainArray &mountainArr) {
        int peak = 0, r = mountainArr.length() - 1;
        while (peak < r) {
            int m = peak + (r - peak) / 2;
            if (mountainArr.get(m) > mountainArr.get(m + 1)) r = m;
            else peak = m + 1;
        }
        int res = helper(mountainArr, target, 0, peak, true);
        return res != -1 ? res : helper(mountainArr, target, peak + 1, mountainArr.length() - 1, false);
    }
};