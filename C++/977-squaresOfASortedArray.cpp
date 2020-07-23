#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int pow2(int i) {
    return i * i;
}

vector<int> sortedSquares(vector<int>& A) {
    for (auto& x : A) x = pow2(x);
    sort(A.begin(), A.end());
    return A;
}