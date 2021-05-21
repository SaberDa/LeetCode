class Solution {
public:
    int totalMoney(int n) {
        int res = 0, monday = 1, money = 1;
        for (int i = 1; i <= n; i++) {
            if (i % 7 == 1) {
                money = monday;
                monday++;
            }
            res += money;
            money++;
        }
        return res;
    }
};