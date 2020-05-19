#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<vector<int>> intervalIntersection(vector<vector<int>>& A, vector<vector<int>>& B) {
        vector<vector<int>> res;
        for (int i = 0, j = 0; i < A.size() && j < B.size();) {
            int low = max(A[i][0], B[j][0]);
            int high = min(A[i][1], B[j][1]);
            if (low <= high) {
                res.push_back({low, high});
            }
            if (high == A[i][1]) {
                i++;
            } else {
                j++;
            }
        }
        return res;
}