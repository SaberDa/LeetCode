class Solution {
public:
    int maxChunkToSorted(vector<int> &arr) {
        int res = 0, i = 0;
        int temp = -1;
        while (i < arr.size()) {
            temp = max(temp, arr[i]);
            if (i == temp) res++;
            i++;
        }
        return res;
    }
};