#include <vector>
#include <algorithm>

using namespace std;

vector<int> pancakeSort(vector<int> &A) {

    /*
     * Find the index i of the next maximum number x
     * Reverse i+1 numbers, so that the x will be at A[0]
     * Reverse x numbers, so that the x will be at A[x - 1]
     * Repeat this process N times
    */

    vector<int> res;
    int i, x;
    for (x = A.size(); x > 0; x--) {
        for (i = 0; A[i] != x; i++);
        reverse(A.begin(), A.begin() + i + 1);
        res.push_back(i + 1);
        reverse(A.begin(), A.begin() + x);
        res.push_back(x);
    }
    return res;
}