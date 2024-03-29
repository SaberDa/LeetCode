class Solution {
public:
    int secondHighest(string s) {
        int first = -1, second = -1;
        for (auto c : s) {
            if (isdigit(c)) {
                int cur = c - '0';
                if (cur > first) {
                    second = first;
                    first = cur;
                } else if (cur != first && cur > second) {
                    second = cur;    
                }
            }
        }
        return second;
    }
};