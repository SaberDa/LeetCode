class Solution {
public:
    int countBalls(int lowLimit, int highLimit) {
        vector<int> res(46, 0);
        for (int i = lowLimit; i <= highLimit; i++) {
            int sum = 0, n = i;
            while (n) {
                sum += n % 10;
                n /= 10;
            }
            res[sum]++;
        }
        return *max_element(res.begin(), res.end());
    }
};