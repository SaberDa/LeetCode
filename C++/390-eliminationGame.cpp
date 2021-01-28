class Solution {
public:
    int lastRemaining(int n) {
        int res = 1, distance = 1;
        while (distance * 2 <= n) {
            res += distance;
            distance *= 2;
            if (distance * 2 > n) break;
            if ((n / distance) % 2) res += distance;
            distance *= 2;
        }
        return res;
    }
};