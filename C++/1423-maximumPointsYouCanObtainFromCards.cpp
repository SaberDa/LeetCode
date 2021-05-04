class Solution {
public:
    int maxScore(vector<int> &cardPoints, int k) {
        int i = 0, j = 0;
        int size = cardPoints.size();
        int total = 0, sum = 0, temp = 0;
        total = accumulate(cardPoints.begin(), cardPoints.end(), 0);
        while (j < size - k) sum += cardPoints[j++];
        temp = sum;
        while (j < size) {
            sum += cardPoints[j++];
            sum -= cardPoints[i++];
            temp = min(sum, temp);
        }
        return total - temp;
    }
};