#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> generateMatrix(int n) {
    vector<vector<int>> res(n, vector<int>(n, 0));
    if (n == 0) {
        return res;
    }
    help(res, 0, n - 1, 0, n - 1, 1, n);
    return res;
}

void help(vector<vector<int>>& res, int minRow, int maxRow, int minCol, int maxCol, int k ,int n) {
    if (k > n * n) {
        return;
    }
    if (k == n * n) {
        res[minRow][minCol] = k;
        return;
    }
    for (int i = minCol; i <= maxCol; i++) {
        res[minRow][i] = k;
        k++;
    }
    minRow++;
    for (int i = minRow; i <= maxRow; i++) {
        res[i][maxCol] = k;
        k++;
    }
    maxCol--;
    for (int i = maxCol; i >= minCol; i--) {
        res[maxRow][i] = k;
        k++;
    }
    maxRow--;
    for (int i = maxRow; i >= minRow; i--) {
        res[i][minCol] = k;
        k++;
    }
    minCol++;
    help(res, minRow, maxRow, minCol, maxCol, k , n);
}