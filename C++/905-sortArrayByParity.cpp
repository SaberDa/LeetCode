#include <iostream>
#include <vector>

using namespace std;

vector<int> sortArrayByParity(vector<int>& A) {
    int pos = -1;
    for (int i = 0; i < A.size(); i++) {
        if (A[i] % 2 == 0) {
            pos++;
            swap(A[i], A[pos]);
        }
    }
    return A;
}