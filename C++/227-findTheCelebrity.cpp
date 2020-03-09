// Forward declaration of the knows API.
bool knows(int a, int b);

class Solution {
public:
    int findCelebrity(int n) {
        int j = 0, i = 0;
        while (j < n) {
            if (knows(j, i) == 0) {
                i = j;
            }
            j++;
        }
        for (int k = 0; k < n; k++) {
            if (i == k) continue;
            if (knows(i, k) || !knows(k, i)) {
                return -1;
            }
        }
        return i;
    }
};